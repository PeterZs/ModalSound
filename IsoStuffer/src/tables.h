/******************************************************************************
 *  File: tables.h
 *
 *  This file is part of isostuffer
 *
 *  This program is free software: you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation, either version 3 of the License, or
 *  (at your option) any later version.
 *
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with this program.  If not, see <http://www.gnu.org/licenses/>.
 ******************************************************************************/
#ifndef ISOSTUFFING_TABLES_H
#   define ISOSTUFFING_TABLES_H

namespace IsoStuffing
{

//-----------------------------------------------------------------------------
// Tables for Cube
/*
 *                         E11
 *             4--------------------------5
 *            /.                         /|
 *           / .                        / |
 *        E5/  .                     E6/  |
 *         /   .E0                    /   |E1
 *        /    .                     /    |    y^
 *       7--------------------------6     |     |
 *       |     .    E10             |     |     |
 *       |     .                    |     |     |
 *       |     .                    |     |     |
 *       |     0....................|.....1     0---------> x
 *       |E3   .          E8        |E2   /    /
 *       |    .                     |    /    /
 *       |   .                      |   /    /
 *       |  .E4                     |  /E7  z
 *       | .                        | /
 *       |.                         |/
 *       3--------------------------2
 *                  E9
 */

static const int FACE_MASK[] = {
    (1<<3)|(1<<7)|(1<<4)|1 ,
    (1<<1)|(1<<5)|(1<<6)|(1<<2),
         1|(1<<1)|(1<<2)|(1<<3),
    (1<<4)|(1<<7)|(1<<6)|(1<<5),
    (1<<4)|(1<<5)|(1<<1)|1,
    (1<<3)|(1<<2)|(1<<6)|(1<<7) };

static const int EDGE_DIAG_DIR[][3] = {
        {-1,  0, -1}, { 1,  0, -1}, { 1,  0,  1}, {-1,  0,  1},
        {-1, -1,  0}, {-1,  1,  0}, { 1,  1,  0}, { 1, -1,  0},
        { 0, -1, -1}, { 0, -1,  1}, { 0,  1,  1}, { 0,  1, -1} };

static const int EDGE_DIAG_EDGE[] = {
        2, 3, 0, 1, 6, 7, 4, 5, 10, 11, 8, 9};

static const int CORNER_EDGES[][3] = {
        {8, 0, 4}, {8, 1, 7}, {9, 2, 7}, {9, 3, 4},
        {11, 0, 5}, {11, 1, 6}, {10, 2, 6}, {10, 3, 5} };

static const int D_CORNERS[][3] = { 
        {0, 0, 0}, {1, 0, 0}, {1, 0, 1}, {0, 0, 1},
        {0, 1, 0}, {1, 1, 0}, {1, 1, 1}, {0, 1, 1} };

/*
 * index of each vertex on 6 faces
 */
static const int IDX_FACES[][4] = { 
        {3, 7, 4, 0}, {1, 5, 6, 2}, 
        {0, 1, 2, 3}, {4, 7, 6, 5}, 
        {4, 5, 1, 0}, {3, 2, 6, 7} };
/*!
 * index of each edge on 6 faces
 */
static const int IDX_EDGE_FACES[][4] = { 
        {3, 5, 0,  4}, {1, 6, 2, 7},
        {8, 7, 9,  4}, {5, 10, 6, 11},
        {11, 1, 8, 0}, {9, 2, 10, 3} };

/*!
 * index of each vertex on 12 edges
 */
static const int IDX_EDGES[][2] = { 
        {0, 4}, {1, 5}, {2, 6}, {3, 7}, 
        {0, 3}, {4, 7}, {5, 6}, {1, 2},
        {0, 1}, {2, 3}, {6, 7}, {4, 5} };

static const int IDX_EDGES_MASK[] = {
        1|(1<<4), (1<<1)|(1<<5), (1<<2)|(1<<6), (1<<3)|(1<<7),
        1|(1<<3), (1<<4)|(1<<7), (1<<5)|(1<<6), (1<<1)|(1<<2),
        1|(1<<1), (1<<2)|(1<<3), (1<<6)|(1<<7), (1<<4)|(1<<5) };

static const int CHILD_CENTERED_MASK[][2] = {
        { 1|(1<<2)|(1<<4), (1<<8)|1|(1<<4) },               //{0, 2, 4, 8, 0, 4},
        { (1<<1)|(1<<2)|(1<<4), (1<<8)|(1<<1)|(1<<7) },     //{1, 2, 4, 8, 1, 7},
        { (1<<1)|(1<<2)|(1<<5), (1<<9)|(1<<2)|(1<<7) },     // {1, 2, 5, 9, 2, 7},
        { 1|(1<<2)|(1<<5), (1<<9)|(1<<3)|(1<<4) },          //{0, 2, 5, 9, 3, 4},
        { 1|(1<<3)|(1<<4), (1<<11)|1|(1<<5) },              //{0, 3, 4, 11, 0, 5},
        { (1<<1)|(1<<3)|(1<<4), (1<<11)|(1<<1)|(1<<6) },    //{1, 3, 4, 11, 1, 6},
        { (1<<1)|(1<<3)|(1<<5), (1<<10)|(1<<2)|(1<<6) },    //{1, 3, 5, 10, 2, 6},
        { 1|(1<<3)|(1<<5), (1<<10)|(1<<3)|(1<<5) } };       //{0, 3, 5, 10, 3, 5} };

static const int CHILD_ADJOIN_CENTERED_MASK[][3][2] = {
       {{1<<1, (1<<1)|(1<<7)}, {1<<3, (1<<5)|(1<<11)}, {1<<5, (1<<3)|(1<<9)}},  //{{1, 1, 7}, {3, 5, 11}, {5, 3, 9}},
       {{1, 1|(1<<4)}, {1<<3, (1<<6)|(1<<11)}, {1<<5, (1<<2)|(1<<9)}},          //{{0, 0, 4}, {3, 6, 11}, {5, 2, 9}},
       {{1, (1<<3)|(1<<4)}, {1<<3, (1<<6)|(1<<10)}, {1<<4, (1<<1)|(1<<8)}},     //{{0, 3, 4}, {3, 6, 10}, {4, 1, 8}},
       {{1<<1, (1<<2)|(1<<7)}, {1<<3, (1<<5)|(1<<10)}, {1<<4, 1|(1<<8)}},       //{{1, 2, 7}, {3, 5, 10}, {4, 0, 8}},
       {{1<<1, (1<<1)|(1<<6)}, {1<<2, (1<<4)|(1<<8)}, {1<<5, (1<<3)|(1<<10)}},  //{{1, 1, 6}, {2, 4, 8 }, {5, 3, 10}},
       {{1, 1|(1<<5)}, {1<<2, (1<<7)|(1<<8)}, {1<<5, (1<<2)|(1<<10)}},          //{{0, 0, 5}, {2, 7, 8 }, {5, 2, 10}},
       {{1, (1<<3)|(1<<5)}, {1<<2, (1<<7)|(1<<9)}, {1<<4, (1<<1)|(1<<11)}},     //{{0, 3, 5}, {2, 7, 9 }, {4, 1, 11}},
       {{1<<1, (1<<2)|(1<<6)}, {1<<2, (1<<4)|(1<<9)}, {1<<4, 1|(1<<11)}} };     //{{1, 2, 6}, {2, 4, 9 }, {4, 0, 11}} };


static const int D_COVTX[][3] = { 
        {-1, -1, -1}, {1, -1, -1}, {1, -1, 1}, {-1, -1, 1},
        {-1,  1, -1}, {1,  1, -1}, {1,  1, 1}, {-1,  1, 1} };

//-----------------------------------------------------------------------------
// Tables for Tetrahedron
/*
 *            v3
 *           /| \
 *          / |  \
 *         /  |   \  
 *      e3/f0 |    \e5
 *       /    |     \
 *      /     |e4    \  
 *     /  e2  |       \
 *    v0......|........v2
 *     \      |       /
 *       \    | f1  /  
 *      e0 \  |   /e1
 *           \| / 
 *            v1
 */
/*
 * Map from pair of vertice to the connecting edges
 */
static const int TET_PVTX_EDGE[][4] = {
        {-1, 0, 2, 3},
        { 0,-1, 1, 4},
        { 2, 1,-1, 5},
        { 3, 4, 5,-1} };


/*
static const int D_FACES[][3] = { {-1,  0,  0}, {1, 0, 0},
                                  { 0, -1,  0}, {0, 1, 0}, 
                                  { 0,  0, -1}, {0, 0, 1} };
*/
/*
static const int OPS_FACE_EDGE[][3][4] = {
        { {5, 7, 2, 1}, {5, 5, 7, 11}, {2, 3, 7, 9} },  // node 0
        { {4, 4, 3, 0}, {4, 6, 6, 11}, {3, 2, 6, 9} },
        { {7, 4, 0, 3}, {5, 10, 7, 6}, {5, 8, 0, 1} },
        { {6, 7, 1, 2}, {6, 5, 4, 10}, {1, 0, 4, 8} },
        { {6, 1, 1, 6}, {1, 4, 3, 8}, {6, 3, 3, 10} },
        { {7, 0, 0, 5}, {2, 8, 0, 7}, {7, 2, 2, 10} },
        { {4, 3, 3, 5}, {1, 9, 3, 7}, {4, 1, 1, 11} }, 
        { {5, 2, 2, 6}, {0, 9, 2, 4}, {5, 0, 0, 11} } };

static const int IDX_OPS_CHD[][3] = { 
        {1, 4, 3}, {0, 5, 2}, {3, 6, 1}, {2, 7, 0},
        {5, 0, 7}, {4, 1, 6}, {7, 2, 5}, {6, 3, 4} };
*/
/*
static const int DIAG_CORNER_IDX[][3] = {
        {7, 2, 5}, {6, 3, 4}, {5, 0, 7}, {4, 1, 6},
        {3, 6, 1}, {2, 7, 0}, {1, 4, 3}, {0, 5, 2} };
*/




}

#endif