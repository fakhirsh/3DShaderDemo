/*
created with obj2opengl.pl

source file    : ./needle.obj
vertices       : 33
faces          : 34
normals        : 33
texture coords : 35


// include generated arrays
#import "./needle.h"

// set input data to arrays
glVertexPointer(3, GL_FLOAT, 0, needleVerts);
glNormalPointer(GL_FLOAT, 0, needleNormals);
glTexCoordPointer(2, GL_FLOAT, 0, needleTexCoords);

// draw data
glDrawArrays(GL_TRIANGLES, 0, needleNumVerts);
*/

unsigned int needleNumVerts = 102;

float needleVerts [] = {
  // f 32/1/1 10/2/1 33/3/1
  -0.0372466315791326, -0.0938705380797752, 0.0303030303030303,
  -1.2025063035771e-18, 5.33228991088591e-08, -0.96969696969697,
  -0.0189884443412113, -0.0996527666132958, 0.0303030303030303,
  // f 1/1/2 10/2/2 2/3/2
  -1.2025063035771e-18, -0.101605984407638, 0.0303030303030303,
  -1.2025063035771e-18, 5.33228991088591e-08, -0.96969696969697,
  0.0189884443412113, -0.0996527666132958, 0.0303030303030303,
  // f 31/1/3 10/2/3 32/3/3
  -0.0540742187568736, -0.084481015421569, 0.0303030303030303,
  -1.2025063035771e-18, 5.33228991088591e-08, -0.96969696969697,
  -0.0372466315791326, -0.0938705380797752, 0.0303030303030303,
  // f 30/1/4 10/2/4 31/3/4
  -0.0688218929319911, -0.0718466877068162, 0.0303030303030303,
  -1.2025063035771e-18, 5.33228991088591e-08, -0.96969696969697,
  -0.0540742187568736, -0.084481015421569, 0.0303030303030303,
  // f 29/1/5 10/2/5 30/3/5
  -0.0809265642898997, -0.0564497005892554, 0.0303030303030303,
  -1.2025063035771e-18, 5.33228991088591e-08, -0.96969696969697,
  -0.0688218929319911, -0.0718466877068162, 0.0303030303030303,
  // f 28/1/6 10/2/6 29/3/6
  -0.0899219240778964, -0.0388830580298714, 0.0303030303030303,
  -1.2025063035771e-18, 5.33228991088591e-08, -0.96969696969697,
  -0.0809265642898997, -0.0564497005892554, 0.0303030303030303,
  // f 27/1/7 10/2/7 28/3/7
  -0.0954595604732066, -0.0198224678061664, 0.0303030303030303,
  -1.2025063035771e-18, 5.33228991088591e-08, -0.96969696969697,
  -0.0899219240778964, -0.0388830580298714, 0.0303030303030303,
  // f 26/1/8 10/2/8 27/3/8
  -0.0973300744510314, 5.33228991088591e-08, 0.0303030303030303,
  -1.2025063035771e-18, 5.33228991088591e-08, -0.96969696969697,
  -0.0954595604732066, -0.0198224678061664, 0.0303030303030303,
  // f 25/1/9 10/2/9 26/3/9
  -0.0954595604732066, 0.0198225744519646, 0.0303030303030303,
  -1.2025063035771e-18, 5.33228991088591e-08, -0.96969696969697,
  -0.0973300744510314, 5.33228991088591e-08, 0.0303030303030303,
  // f 24/1/10 10/2/10 25/3/10
  -0.0899219240778964, 0.0388831646756696, 0.0303030303030303,
  -1.2025063035771e-18, 5.33228991088591e-08, -0.96969696969697,
  -0.0954595604732066, 0.0198225744519646, 0.0303030303030303,
  // f 23/1/11 10/2/11 24/3/11
  -0.0809265642898997, 0.056448047579383, 0.0303030303030303,
  -1.2025063035771e-18, 5.33228991088591e-08, -0.96969696969697,
  -0.0899219240778964, 0.0388831646756696, 0.0303030303030303,
  // f 22/1/12 10/2/12 23/3/12
  -0.0688218929319911, 0.0718450346969438, 0.0303030303030303,
  -1.2025063035771e-18, 5.33228991088591e-08, -0.96969696969697,
  -0.0809265642898997, 0.056448047579383, 0.0303030303030303,
  // f 21/1/13 10/2/13 22/3/13
  -0.0540742187568736, 0.0844811220673672, 0.0303030303030303,
  -1.2025063035771e-18, 5.33228991088591e-08, -0.96969696969697,
  -0.0688218929319911, 0.0718450346969438, 0.0303030303030303,
  // f 20/1/14 10/2/14 21/3/14
  -0.0372466315791326, 0.0938706447255734, 0.0303030303030303,
  -1.2025063035771e-18, 5.33228991088591e-08, -0.96969696969697,
  -0.0540742187568736, 0.0844811220673672, 0.0303030303030303,
  // f 19/1/15 10/2/15 20/3/15
  -0.0189884443412113, 0.099652873259094, 0.0303030303030303,
  -1.2025063035771e-18, 5.33228991088591e-08, -0.96969696969697,
  -0.0372466315791326, 0.0938706447255734, 0.0303030303030303,
  // f 18/1/16 10/2/16 19/3/16
  -1.2025063035771e-18, 0.101606091053436, 0.0303030303030303,
  -1.2025063035771e-18, 5.33228991088591e-08, -0.96969696969697,
  -0.0189884443412113, 0.099652873259094, 0.0303030303030303,
  // f 17/1/17 10/2/17 18/3/17
  0.0189884443412113, 0.099652873259094, 0.0303030303030303,
  -1.2025063035771e-18, 5.33228991088591e-08, -0.96969696969697,
  -1.2025063035771e-18, 0.101606091053436, 0.0303030303030303,
  // f 16/1/18 10/2/18 17/3/18
  0.0372466315791326, 0.0938706447255734, 0.0303030303030303,
  -1.2025063035771e-18, 5.33228991088591e-08, -0.96969696969697,
  0.0189884443412113, 0.099652873259094, 0.0303030303030303,
  // f 15/1/19 10/2/19 16/3/19
  0.0540742187568736, 0.0844811220673672, 0.0303030303030303,
  -1.2025063035771e-18, 5.33228991088591e-08, -0.96969696969697,
  0.0372466315791326, 0.0938706447255734, 0.0303030303030303,
  // f 14/1/20 10/2/20 15/3/20
  0.0688218929319911, 0.0718450346969438, 0.0303030303030303,
  -1.2025063035771e-18, 5.33228991088591e-08, -0.96969696969697,
  0.0540742187568736, 0.0844811220673672, 0.0303030303030303,
  // f 13/1/21 10/2/21 14/3/21
  0.0809265642898997, 0.0564498072350536, 0.0303030303030303,
  -1.2025063035771e-18, 5.33228991088591e-08, -0.96969696969697,
  0.0688218929319911, 0.0718450346969438, 0.0303030303030303,
  // f 12/1/22 10/2/22 13/3/22
  0.0899219240778964, 0.0388831646756696, 0.0303030303030303,
  -1.2025063035771e-18, 5.33228991088591e-08, -0.96969696969697,
  0.0809265642898997, 0.0564498072350536, 0.0303030303030303,
  // f 11/1/23 10/2/23 12/3/23
  0.0954595604732066, 0.0198225744519646, 0.0303030303030303,
  -1.2025063035771e-18, 5.33228991088591e-08, -0.96969696969697,
  0.0899219240778964, 0.0388831646756696, 0.0303030303030303,
  // f 9/1/24 10/2/24 11/3/24
  0.0973300744510314, 5.33228991088591e-08, 0.0303030303030303,
  -1.2025063035771e-18, 5.33228991088591e-08, -0.96969696969697,
  0.0954595604732066, 0.0198225744519646, 0.0303030303030303,
  // f 8/1/25 10/2/25 9/3/25
  0.0954595604732066, -0.0198224678061664, 0.0303030303030303,
  -1.2025063035771e-18, 5.33228991088591e-08, -0.96969696969697,
  0.0973300744510314, 5.33228991088591e-08, 0.0303030303030303,
  // f 7/1/26 10/2/26 8/3/26
  0.0899219240778964, -0.0388830580298714, 0.0303030303030303,
  -1.2025063035771e-18, 5.33228991088591e-08, -0.96969696969697,
  0.0954595604732066, -0.0198224678061664, 0.0303030303030303,
  // f 6/1/27 10/2/27 7/3/27
  0.0809265642898997, -0.0564479409335848, 0.0303030303030303,
  -1.2025063035771e-18, 5.33228991088591e-08, -0.96969696969697,
  0.0899219240778964, -0.0388830580298714, 0.0303030303030303,
  // f 5/1/28 10/2/28 6/3/28
  0.0688218929319911, -0.0718449280511456, 0.0303030303030303,
  -1.2025063035771e-18, 5.33228991088591e-08, -0.96969696969697,
  0.0809265642898997, -0.0564479409335848, 0.0303030303030303,
  // f 4/1/29 10/2/29 5/3/29
  0.0540742187568736, -0.084481015421569, 0.0303030303030303,
  -1.2025063035771e-18, 5.33228991088591e-08, -0.96969696969697,
  0.0688218929319911, -0.0718449280511456, 0.0303030303030303,
  // f 3/1/30 10/2/30 4/3/30
  0.0372466315791326, -0.0938705380797752, 0.0303030303030303,
  -1.2025063035771e-18, 5.33228991088591e-08, -0.96969696969697,
  0.0540742187568736, -0.084481015421569, 0.0303030303030303,
  // f 33/1/31 10/2/31 1/3/31
  -0.0189884443412113, -0.0996527666132958, 0.0303030303030303,
  -1.2025063035771e-18, 5.33228991088591e-08, -0.96969696969697,
  -1.2025063035771e-18, -0.101605984407638, 0.0303030303030303,
  // f 2/1/32 10/2/32 3/3/32
  0.0189884443412113, -0.0996527666132958, 0.0303030303030303,
  -1.2025063035771e-18, 5.33228991088591e-08, -0.96969696969697,
  0.0372466315791326, -0.0938705380797752, 0.0303030303030303,
  // f 1/4/33 2/5/33 3/6/33 4/7/33 5/8/33 6/9/33 7/10/33 8/11/33 9/12/33 11/13/33 12/14/33 13/15/33 14/16/33 15/17/33 16/18/33 17/19/33 18/20/33 19/21/33 20/22/33 21/23/33 22/24/33 23/25/33 24/26/33 25/27/33 26/28/33 27/29/33 28/30/33 29/31/33 30/32/33 31/33/33 32/34/33 33/35/33
  -1.2025063035771e-18, -0.101605984407638, 0.0303030303030303,
  0.0189884443412113, -0.0996527666132958, 0.0303030303030303,
  0.0372466315791326, -0.0938705380797752, 0.0303030303030303,
  // f 1/4/33 2/5/33 3/6/33 4/7/33 5/8/33 6/9/33 7/10/33 8/11/33 9/12/33 11/13/33 12/14/33 13/15/33 14/16/33 15/17/33 16/18/33 17/19/33 18/20/33 19/21/33 20/22/33 21/23/33 22/24/33 23/25/33 24/26/33 25/27/33 26/28/33 27/29/33 28/30/33 29/31/33 30/32/33 31/33/33 32/34/33 33/35/33
  -1.2025063035771e-18, -0.101605984407638, 0.0303030303030303,
  0.0540742187568736, -0.084481015421569, 0.0303030303030303,
  0.0372466315791326, -0.0938705380797752, 0.0303030303030303,
};

float needleNormals [] = {
  // f 32/1/1 10/2/1 33/3/1
  -0.300410146524051, -0.948532037210594, -0.100203384426464,
  -0.300410146524051, -0.948532037210594, -0.100203384426464,
  -0.300410146524051, -0.948532037210594, -0.100203384426464,
  // f 1/1/2 10/2/2 2/3/2
  0.101800524783058, -0.989705101942951, -0.10060051859701,
  0.101800524783058, -0.989705101942951, -0.10060051859701,
  0.101800524783058, -0.989705101942951, -0.10060051859701,
  // f 31/1/3 10/2/3 32/3/3
  -0.484814930105662, -0.868926759011572, -0.0996030673236881,
  -0.484814930105662, -0.868926759011572, -0.0996030673236881,
  -0.484814930105662, -0.868926759011572, -0.0996030673236881,
  // f 30/1/4 10/2/4 31/3/4
  -0.647403088120096, -0.755703604714792, -0.0989004717563754,
  -0.647403088120096, -0.755703604714792, -0.0989004717563754,
  -0.647403088120096, -0.755703604714792, -0.0989004717563754,
  // f 29/1/5 10/2/5 30/3/5
  -0.782360190614525, -0.6150687030253, -0.0979950136505924,
  -0.782360190614525, -0.6150687030253, -0.0979950136505924,
  -0.782360190614525, -0.6150687030253, -0.0979950136505924,
  // f 28/1/6 10/2/6 29/3/6
  -0.885882698879835, -0.45359114145151, -0.0972980997866666,
  -0.885882698879835, -0.45359114145151, -0.0972980997866666,
  -0.885882698879835, -0.45359114145151, -0.0972980997866666,
  // f 27/1/7 10/2/7 28/3/7
  -0.955789572392648, -0.27769697034258, -0.0966989450202647,
  -0.955789572392648, -0.27769697034258, -0.0966989450202647,
  -0.955789572392648, -0.27769697034258, -0.0966989450202647,
  // f 26/1/8 10/2/8 27/3/8
  -0.990940619488506, -0.0935038328006614, -0.0964039516789706,
  -0.990940619488506, -0.0935038328006614, -0.0964039516789706,
  -0.990940619488506, -0.0935038328006614, -0.0964039516789706,
  // f 25/1/9 10/2/9 26/3/9
  -0.990940619488506, 0.0935038328006614, -0.0964039516789706,
  -0.990940619488506, 0.0935038328006614, -0.0964039516789706,
  -0.990940619488506, 0.0935038328006614, -0.0964039516789706,
  // f 24/1/10 10/2/10 25/3/10
  -0.955789572392648, 0.27769697034258, -0.0966989450202647,
  -0.955789572392648, 0.27769697034258, -0.0966989450202647,
  -0.955789572392648, 0.27769697034258, -0.0966989450202647,
  // f 23/1/11 10/2/11 24/3/11
  -0.885882698879835, 0.45359114145151, -0.0972980997866666,
  -0.885882698879835, 0.45359114145151, -0.0972980997866666,
  -0.885882698879835, 0.45359114145151, -0.0972980997866666,
  // f 22/1/12 10/2/12 23/3/12
  -0.782360190614525, 0.6150687030253, -0.0979950136505924,
  -0.782360190614525, 0.6150687030253, -0.0979950136505924,
  -0.782360190614525, 0.6150687030253, -0.0979950136505924,
  // f 21/1/13 10/2/13 22/3/13
  -0.647403088120096, 0.755703604714792, -0.0989004717563754,
  -0.647403088120096, 0.755703604714792, -0.0989004717563754,
  -0.647403088120096, 0.755703604714792, -0.0989004717563754,
  // f 20/1/14 10/2/14 21/3/14
  -0.484814930105662, 0.868926759011572, -0.0996030673236881,
  -0.484814930105662, 0.868926759011572, -0.0996030673236881,
  -0.484814930105662, 0.868926759011572, -0.0996030673236881,
  // f 19/1/15 10/2/15 20/3/15
  -0.300410146524051, 0.948532037210594, -0.100203384426464,
  -0.300410146524051, 0.948532037210594, -0.100203384426464,
  -0.300410146524051, 0.948532037210594, -0.100203384426464,
  // f 18/1/16 10/2/16 19/3/16
  -0.101800524783058, 0.989705101942951, -0.10060051859701,
  -0.101800524783058, 0.989705101942951, -0.10060051859701,
  -0.101800524783058, 0.989705101942951, -0.10060051859701,
  // f 17/1/17 10/2/17 18/3/17
  0.101800524783058, 0.989705101942951, -0.10060051859701,
  0.101800524783058, 0.989705101942951, -0.10060051859701,
  0.101800524783058, 0.989705101942951, -0.10060051859701,
  // f 16/1/18 10/2/18 17/3/18
  0.300410146524051, 0.948532037210594, -0.100203384426464,
  0.300410146524051, 0.948532037210594, -0.100203384426464,
  0.300410146524051, 0.948532037210594, -0.100203384426464,
  // f 15/1/19 10/2/19 16/3/19
  0.484814930105662, 0.868926759011572, -0.0996030673236881,
  0.484814930105662, 0.868926759011572, -0.0996030673236881,
  0.484814930105662, 0.868926759011572, -0.0996030673236881,
  // f 14/1/20 10/2/20 15/3/20
  0.647403088120096, 0.755703604714792, -0.0989004717563754,
  0.647403088120096, 0.755703604714792, -0.0989004717563754,
  0.647403088120096, 0.755703604714792, -0.0989004717563754,
  // f 13/1/21 10/2/21 14/3/21
  0.782360190614525, 0.6150687030253, -0.0979950136505924,
  0.782360190614525, 0.6150687030253, -0.0979950136505924,
  0.782360190614525, 0.6150687030253, -0.0979950136505924,
  // f 12/1/22 10/2/22 13/3/22
  0.885882698879835, 0.45359114145151, -0.0972980997866666,
  0.885882698879835, 0.45359114145151, -0.0972980997866666,
  0.885882698879835, 0.45359114145151, -0.0972980997866666,
  // f 11/1/23 10/2/23 12/3/23
  0.955789572392648, 0.27769697034258, -0.0966989450202647,
  0.955789572392648, 0.27769697034258, -0.0966989450202647,
  0.955789572392648, 0.27769697034258, -0.0966989450202647,
  // f 9/1/24 10/2/24 11/3/24
  0.990940619488506, 0.0935038328006614, -0.0964039516789706,
  0.990940619488506, 0.0935038328006614, -0.0964039516789706,
  0.990940619488506, 0.0935038328006614, -0.0964039516789706,
  // f 8/1/25 10/2/25 9/3/25
  0.990940619488506, -0.0935038328006614, -0.0964039516789706,
  0.990940619488506, -0.0935038328006614, -0.0964039516789706,
  0.990940619488506, -0.0935038328006614, -0.0964039516789706,
  // f 7/1/26 10/2/26 8/3/26
  0.955789572392648, -0.27769697034258, -0.0966989450202647,
  0.955789572392648, -0.27769697034258, -0.0966989450202647,
  0.955789572392648, -0.27769697034258, -0.0966989450202647,
  // f 6/1/27 10/2/27 7/3/27
  0.885882698879835, -0.45359114145151, -0.0972980997866666,
  0.885882698879835, -0.45359114145151, -0.0972980997866666,
  0.885882698879835, -0.45359114145151, -0.0972980997866666,
  // f 5/1/28 10/2/28 6/3/28
  0.782360190614525, -0.6150687030253, -0.0979950136505924,
  0.782360190614525, -0.6150687030253, -0.0979950136505924,
  0.782360190614525, -0.6150687030253, -0.0979950136505924,
  // f 4/1/29 10/2/29 5/3/29
  0.647403088120096, -0.755703604714792, -0.0989004717563754,
  0.647403088120096, -0.755703604714792, -0.0989004717563754,
  0.647403088120096, -0.755703604714792, -0.0989004717563754,
  // f 3/1/30 10/2/30 4/3/30
  0.484814930105662, -0.868926759011572, -0.0996030673236881,
  0.484814930105662, -0.868926759011572, -0.0996030673236881,
  0.484814930105662, -0.868926759011572, -0.0996030673236881,
  // f 33/1/31 10/2/31 1/3/31
  -0.101800524783058, -0.989705101942951, -0.10060051859701,
  -0.101800524783058, -0.989705101942951, -0.10060051859701,
  -0.101800524783058, -0.989705101942951, -0.10060051859701,
  // f 2/1/32 10/2/32 3/3/32
  0.300410146524051, -0.948532037210594, -0.100203384426464,
  0.300410146524051, -0.948532037210594, -0.100203384426464,
  0.300410146524051, -0.948532037210594, -0.100203384426464,
  // f 1/4/33 2/5/33 3/6/33 4/7/33 5/8/33 6/9/33 7/10/33 8/11/33 9/12/33 11/13/33 12/14/33 13/15/33 14/16/33 15/17/33 16/18/33 17/19/33 18/20/33 19/21/33 20/22/33 21/23/33 22/24/33 23/25/33 24/26/33 25/27/33 26/28/33 27/29/33 28/30/33 29/31/33 30/32/33 31/33/33 32/34/33 33/35/33
  0, 0, 1,
  0, 0, 1,
  0, 0, 1,
  // f 1/4/33 2/5/33 3/6/33 4/7/33 5/8/33 6/9/33 7/10/33 8/11/33 9/12/33 11/13/33 12/14/33 13/15/33 14/16/33 15/17/33 16/18/33 17/19/33 18/20/33 19/21/33 20/22/33 21/23/33 22/24/33 23/25/33 24/26/33 25/27/33 26/28/33 27/29/33 28/30/33 29/31/33 30/32/33 31/33/33 32/34/33 33/35/33
  0, 0, 1,
  0, 0, 1,
  0, 0, 1,
};

float needleTexCoords [] = {
  // f 32/1/1 10/2/1 33/3/1
  0.761083, 0.281627,
  0.725211, 0.079938,
  0.710727, 0.270945,
  // f 1/1/2 10/2/2 2/3/2
  0.761083, 0.281627,
  0.725211, 0.079938,
  0.710727, 0.270945,
  // f 31/1/3 10/2/3 32/3/3
  0.761083, 0.281627,
  0.725211, 0.079938,
  0.710727, 0.270945,
  // f 30/1/4 10/2/4 31/3/4
  0.761083, 0.281627,
  0.725211, 0.079938,
  0.710727, 0.270945,
  // f 29/1/5 10/2/5 30/3/5
  0.761083, 0.281627,
  0.725211, 0.079938,
  0.710727, 0.270945,
  // f 28/1/6 10/2/6 29/3/6
  0.761083, 0.281627,
  0.725211, 0.079938,
  0.710727, 0.270945,
  // f 27/1/7 10/2/7 28/3/7
  0.761083, 0.281627,
  0.725211, 0.079938,
  0.710727, 0.270945,
  // f 26/1/8 10/2/8 27/3/8
  0.761083, 0.281627,
  0.725211, 0.079938,
  0.710727, 0.270945,
  // f 25/1/9 10/2/9 26/3/9
  0.761083, 0.281627,
  0.725211, 0.079938,
  0.710727, 0.270945,
  // f 24/1/10 10/2/10 25/3/10
  0.761083, 0.281627,
  0.725211, 0.079938,
  0.710727, 0.270945,
  // f 23/1/11 10/2/11 24/3/11
  0.761083, 0.281627,
  0.725211, 0.079938,
  0.710727, 0.270945,
  // f 22/1/12 10/2/12 23/3/12
  0.761083, 0.281627,
  0.725211, 0.079938,
  0.710727, 0.270945,
  // f 21/1/13 10/2/13 22/3/13
  0.761083, 0.281627,
  0.725211, 0.079938,
  0.710727, 0.270945,
  // f 20/1/14 10/2/14 21/3/14
  0.761083, 0.281627,
  0.725211, 0.079938,
  0.710727, 0.270945,
  // f 19/1/15 10/2/15 20/3/15
  0.761083, 0.281627,
  0.725211, 0.079938,
  0.710727, 0.270945,
  // f 18/1/16 10/2/16 19/3/16
  0.761083, 0.281627,
  0.725211, 0.079938,
  0.710727, 0.270945,
  // f 17/1/17 10/2/17 18/3/17
  0.761083, 0.281627,
  0.725211, 0.079938,
  0.710727, 0.270945,
  // f 16/1/18 10/2/18 17/3/18
  0.761083, 0.281627,
  0.725211, 0.079938,
  0.710727, 0.270945,
  // f 15/1/19 10/2/19 16/3/19
  0.761083, 0.281627,
  0.725211, 0.079938,
  0.710727, 0.270945,
  // f 14/1/20 10/2/20 15/3/20
  0.761083, 0.281627,
  0.725211, 0.079938,
  0.710727, 0.270945,
  // f 13/1/21 10/2/21 14/3/21
  0.761083, 0.281627,
  0.725211, 0.079938,
  0.710727, 0.270945,
  // f 12/1/22 10/2/22 13/3/22
  0.761083, 0.281627,
  0.725211, 0.079938,
  0.710727, 0.270945,
  // f 11/1/23 10/2/23 12/3/23
  0.761083, 0.281627,
  0.725211, 0.079938,
  0.710727, 0.270945,
  // f 9/1/24 10/2/24 11/3/24
  0.761083, 0.281627,
  0.725211, 0.079938,
  0.710727, 0.270945,
  // f 8/1/25 10/2/25 9/3/25
  0.761083, 0.281627,
  0.725211, 0.079938,
  0.710727, 0.270945,
  // f 7/1/26 10/2/26 8/3/26
  0.761083, 0.281627,
  0.725211, 0.079938,
  0.710727, 0.270945,
  // f 6/1/27 10/2/27 7/3/27
  0.761083, 0.281627,
  0.725211, 0.079938,
  0.710727, 0.270945,
  // f 5/1/28 10/2/28 6/3/28
  0.761083, 0.281627,
  0.725211, 0.079938,
  0.710727, 0.270945,
  // f 4/1/29 10/2/29 5/3/29
  0.761083, 0.281627,
  0.725211, 0.079938,
  0.710727, 0.270945,
  // f 3/1/30 10/2/30 4/3/30
  0.761083, 0.281627,
  0.725211, 0.079938,
  0.710727, 0.270945,
  // f 33/1/31 10/2/31 1/3/31
  0.761083, 0.281627,
  0.725211, 0.079938,
  0.710727, 0.270945,
  // f 2/1/32 10/2/32 3/3/32
  0.761083, 0.281627,
  0.725211, 0.079938,
  0.710727, 0.270945,
  // f 1/4/33 2/5/33 3/6/33 4/7/33 5/8/33 6/9/33 7/10/33 8/11/33 9/12/33 11/13/33 12/14/33 13/15/33 14/16/33 15/17/33 16/18/33 17/19/33 18/20/33 19/21/33 20/22/33 21/23/33 22/24/33 23/25/33 24/26/33 25/27/33 26/28/33 27/29/33 28/30/33 29/31/33 30/32/33 31/33/33 32/34/33 33/35/33
  0.500000, 0,
  0.597545, 0.00960700000000003,
  0.691342, 0.03806,
  // f 1/4/33 2/5/33 3/6/33 4/7/33 5/8/33 6/9/33 7/10/33 8/11/33 9/12/33 11/13/33 12/14/33 13/15/33 14/16/33 15/17/33 16/18/33 17/19/33 18/20/33 19/21/33 20/22/33 21/23/33 22/24/33 23/25/33 24/26/33 25/27/33 26/28/33 27/29/33 28/30/33 29/31/33 30/32/33 31/33/33 32/34/33 33/35/33
  0.500000, 0,
  0.777785, 0.084265,
  0.691342, 0.03806,
};

