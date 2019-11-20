/**
 * @file maptiles.cpp
 * Code for the maptiles function.
 */

#include <iostream>
#include <map>
#include "maptiles.h"
//#include "cs225/RGB_HSL.h"

using namespace std;


Point<3> convertToXYZ(LUVAPixel pixel) {
    return Point<3>( pixel.l, pixel.u, pixel.v );
}

MosaicCanvas* mapTiles(SourceImage const& theSource,
                       vector<TileImage>& theTiles)
{
    /**
     * @todo Implement this function!
     */

    // (1) Convert tiles/LUVA-pixel to XYZ-point/index
    // (2) Find nearest neighbor
    // (3) Convert XYZ-point to index to LUVA-pixel/tile
    // TileImage, Point, and Point-int map indices are all the same!

    // Return NULL for error just in case
    if (!theTiles.size() || !theSource.getRows() || !theSource.getColumns()) return nullptr;
    MosaicCanvas *result = new MosaicCanvas(theSource.getRows(), theSource.getColumns());

    // Turn average colors of each tile image into XYZ points (maps index to point)
    // Map each point to an index
    vector<Point<3>> averageColor(theTiles.size());
    map<Point<3>, int> sourceMap;
    for (size_t i = 0; i < theTiles.size(); i++) {
      averageColor[i] = convertToXYZ(theTiles[i].getAverageColor());
      sourceMap[averageColor[i]] = i;
    }

    // Make averageColor vector into a KD Tree
    KDTree<3> sourceTree(averageColor);

    // Traverse through the source image to make mosaic
    for (int row = 0; row < theSource.getRows(); row++){
      for (int column = 0; column < theSource.getColumns(); column++) {
        // Find the nearest neighbor as an XYZ point, then use map to find index of point in tiles vector
        int index = sourceMap[sourceTree.findNearestNeighbor(convertToXYZ(theSource.getRegionColor(row, column)))];
        result->setTile(row, column, &theTiles[index]);
      }
    }

    return result;
}
