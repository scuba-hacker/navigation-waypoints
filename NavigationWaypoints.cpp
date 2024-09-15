#include "NavigationWaypoints.h"

const char* featureCategoryToString(eWaypointCategory i)
{
  switch (i)
  {
    case BLUE_BUOY:
      return "BLUE BUOY";
    case NO_BUOY:
      return "NO BUOY";
    case PLATFORM:
      return "PLATFORM";
    case CONTAINER:
      return "CONTAINER";
    case ORANGE_BUOY:
      return "ORANGE BUOY";
    case JETTY:
      return "JETTY";
    case UNMARKED:
      return "MYSTERY";
    case UNKNOWN:
      return "UNKNOWN";
    default:
      return "INVALID";
  }; 
}

const std::array<NavigationWaypoint,WAYPOINTS_COUNT> WraysburyWaypoints::waypoints = 
{{
  [0] =  { ._label = "01N Canoe", ._m5label = "01N\nCanoe", ._cat=NO_BUOY, ._lat = 51.4620416774194, ._long = -0.548974709677419},
  [1] =  { ._label = "02N The Sub", ._m5label = "02N\nThe\nSub", ._cat=NO_BUOY, ._lat = 51.4609042894737, ._long = -0.549211315789474},
  [2] =  { ._label = "03N Scimitar Car 5.5m",  ._m5label = "03N\nScimitar\nCar\n5.5m", ._cat=NO_BUOY, ._lat = 51.460347, ._long = -0.5489195},
  [3] =  { ._label = "04N Spitfire Car 6m", ._m5label = "04N\nSpit\n  fire\nCar\n6m", ._cat=NO_BUOY, ._lat = 51.4601028571429, ._long = -0.54883835},
  [4] =  { ._label = "05N Lightning Boat 5.5m", ._m5label = "05N\nLight\n  ning\nBoat\n5.5m", ._cat=NO_BUOY, ._lat = 51.4605855, ._long = -0.548901666666667},
  [5] =  { ._label = "06aN Caves Centre", ._m5label = "06aN\nCaves\nCentre", ._cat=NO_BUOY, ._lat = 51.460947625, ._long = -0.54878325},
  [6] =  { ._label = "06bN Lion Entrance @ Caves", ._m5label = "06bN\nCaves\nLion\nEntrance", ._cat=UNMARKED,._lat = 51.460817, ._long = -0.548734},
  [7] =  { ._label = "06cN Red Isis Bike @ Caves", ._m5label = "06cN\nRed\nIsis\nBike", ._cat=UNMARKED,._lat = 51.460898, ._long = -0.548701333},
  [8] =  { ._label = "06dN Blue Raleigh Bike @ Caves", ._m5label = "06dN\nBlue\nRaleigh\nBike", ._cat=UNMARKED,._lat = 51.4608584444444, ._long = -0.548736333333333},
  [9] =  { ._label = "06eN Cave PC Laptop", ._m5label = "06eN\nCave\nPC\nLaptop", ._cat=UNMARKED, ._lat = 51.460936875, ._long = -0.548774875},
  [10] = { ._label = "07P Cargo 2.5m", ._m5label = "07P\nCargo\n2.5m", ._cat=CONTAINER, ._lat = 51.460014, ._long = -0.548735},
  [11] = { ._label = "08B The Hole 18m", ._m5label = "08B\nThe\nHole\n18m", ._cat=ORANGE_BUOY, ._lat = 51.4604301666667, ._long = -0.548688166666667},
  [12] = { ._label = "09P Dance Platform 6m", ._m5label = "09P 6m\nDance\nPlatform", ._cat=PLATFORM, ._lat = 51.460154, ._long = -0.548687},
  [13] = { ._label = "10N Bus 2m", ._m5label = "10N\n\nBus\n\n2m", ._cat=NO_BUOY,._lat = 51.460073, ._long = -0.548515},
  [14] = { ._label = "11N Confined Area", ._m5label = "11N\nConfined\nArea", ._cat=NO_BUOY, ._lat = 51.4599718333333, ._long = -0.548582833333333},
  [15] = { ._label = "12N Commer Van 6m", ._m5label = "12N\n\nCommer\nVan\n\n6m", BLUE_BUOY, ._lat = 51.4613355909091, ._long = -0.548469727272727},
  [16] = { ._label = "13B White Boat 7m", ._m5label = "13B\nWhite\nBoat\n7m", BLUE_BUOY, ._lat = 51.4605198169044, ._long = -0.548421667307919},
  [17] = { ._label = "14P Cargo 8m", ._m5label = "14P\nCargo\n8m", ._cat=CONTAINER, ._lat = 51.4602986, ._long = -0.5483127},
  [18] = { ._label = "15P Cargo Rusty 8m", ._m5label = "15P\nCargo\nRusty\n8m", ._cat=CONTAINER, ._lat = 51.460192, ._long = -0.548283},
  [19] = { ._label = "16P Portacabin 8m", ._m5label = "16P\nPorta\ncabin\n8m", ._cat=CONTAINER, ._lat = 51.46034, ._long = -0.548173},
  [20] = { ._label = "17P Shallow Platform 2m", ._m5label = "17P 2m", ._cat=PLATFORM, ._lat = 51.4599705, ._long = -0.54810825},
  [21] = { ._label = "18N Milk Float 6.5m", ._m5label = "18N\n\nMilk\nFloat\n\n6.5m", ._cat=NO_BUOY, ._lat = 51.4601745714286, ._long = -0.548058571428571},
  [22] = { ._label = "19N Chicken Hutch Boat 6.5m", ._m5label = "19N\n\nChicken\nHutch\nBoat\n\n6.5m", ._cat=NO_BUOY, ._lat = 51.4604027142857, ._long = -0.54804},
  [23] = { ._label = "20N Skittles Sweet Bowl 5.5m", ._m5label = "20N\n\nSkittle\nSweet\nBowl\n\n5.5m", ._cat=NO_BUOY, ._lat = 51.4600375, ._long = -0.5478815},
  [24] = { ._label = "21B Sticky Up Boat 5m", ._m5label = "21B\n\nSticky\nUp Boat\n\n5m", BLUE_BUOY, ._lat = 51.4602514070597, ._long = -0.54789158281982},
  [25] = { ._label = "22B Lady of Kent Search Light 5m", ._m5label = "22B\nLady of\nKent\nSearch\nLight\n\n5m", BLUE_BUOY, ._lat = 51.4599185714286, ._long = -0.547681},
  [26] = { ._label = "23N Traffic Lights 7m", ._m5label = "23N\n\nTraffic\nLights\n\n7m", ._cat=NO_BUOY, ._lat = 51.4600558888889, ._long = -0.547677333333333},
  [27] = { ._label = "24N Half Die Hard Taxi 8m", ._m5label = "24N\n\nHalf\nDie\nHard\nTaxi 8m", ._cat=NO_BUOY, ._lat = 51.460773, ._long = -0.547620875},
  [28] = { ._label = "25N Boat In A Hole 7m", ._m5label = "25N\n\nBoat In\nA Hole\n\n7m", ._cat=NO_BUOY, ._lat = 51.4599545, ._long = -0.54755475},
  [29] = { ._label = "26N Iron Fish 2m", ._m5label = "26N\nIron\nFish\n2m", ._cat=NO_BUOY, ._lat = 51.4595936666667, ._long = -0.547489833333333},
  [30] = { ._label = "27aB Wreck Site 6m", ._m5label = "27aB\n\nWreck\nSite\n\n6m", BLUE_BUOY, ._lat = 51.4604300973436, ._long = -0.547383365365033},
  [31] = { ._label = "27bB 4 Wreck Site 6m", ._m5label = "27bB\n\n4 Wreck\nSite\n\n6m", BLUE_BUOY, ._lat = 51.46043825, ._long = -0.547208},
  [32] = { ._label = "29B Dive/Spike Boat 7m", ._m5label = "29B\n\nDive/\nSpike\nBoat\n\n7m", BLUE_BUOY, ._lat = 51.4601315714286, ._long = -0.547417857142857},
  [33] = { ._label = "30B White Day boat by platform 6m", ._m5label = "30B\nWhite\nDay\nboat by\nplatform\n6m", BLUE_BUOY, ._lat = 51.4598131428572, ._long = -0.547380285714286},
  [34] = { ._label = "31P 6m", ._m5label = "31P 6m", ._cat=PLATFORM, ._lat = 51.459766, ._long = -0.547347},
  [35] = { ._label = "32P 6m", ._m5label = "32P 6m", ._cat=PLATFORM, ._lat = 51.459658, ._long = -0.54725},
  [36] = { ._label = "33N Port Holes Boat 4.5m", ._m5label = "33N\nPort\nHoles\nBoat 4.5m", ._cat=NO_BUOY, ._lat = 51.4595563333333, ._long = -0.547263333333333},
  [37] = { ._label = "34P 6m", ._m5label = "34P 6m", ._cat=PLATFORM, ._lat = 51.460312, ._long = -0.547165},
  [38] = { ._label = "35N Dragon Boat 7.5m", ._m5label = "35N\n\nDragon\nBoat\n\n7.5m", ._cat=NO_BUOY, ._lat = 51.4599636666667, ._long = -0.547154333333333},
  [39] = { ._label = "36P 6m", ._m5label = "36P 6m", ._cat=PLATFORM, ._lat = 51.459555, ._long = -0.54708},
  [40] = { ._label = "37N Dive Bell 4m", ._m5label = "37N\n\nDive\nBell\n\n4m", ._cat=NO_BUOY, ._lat = 51.4594757058824, ._long = -0.547087117647059},
  [41] = { ._label = "38B Lifeboat 6.5m", ._m5label = "38B\n\nLife\nBoat\n\n6.5m", BLUE_BUOY, ._lat = 51.459839375, ._long = -0.5469307},
  [42] = { ._label = "39N London Black Cab 7m", ._m5label = "39N\n\nLondon\nBlack\nCab\n\n7m", ._cat=NO_BUOY, ._lat = 51.459729, ._long = -0.546992857142857},
  [43] = { ._label = "40N RIB Boat 6m", ._m5label = "40N\n\nRIB\nBoat\n\n6m", ._cat=NO_BUOY, ._lat = 51.460236, ._long = -0.546847571428571},
  [44] = { ._label = "41N Tin/Cabin Boat 7m", ._m5label = "41N\n\nTin\nCabin\nBoat\n\n7m", ._cat=NO_BUOY, ._lat = 51.459676625, ._long = -0.5468125},
  [45] = { ._label = "42P 6m", ._m5label = "42P 6m", ._cat=PLATFORM, ._lat = 51.459491, ._long = -0.546867},
  [46] = { ._label = "43N Thorpe Orange Boat 5.5m", ._m5label = "43N\n\nThorpe\nOrange\nBoat\n\n5.5m", ._cat=NO_BUOY, ._lat = 51.4602073333333, ._long = -0.546787666666667},
  [47] = { ._label = "44N VW Camper Van and Seahorse 5.5m", ._m5label = "44N\nVW\nCamper\nVan and\nSeahors\n\n5.5m", ._cat=NO_BUOY, ._lat = 51.459368, ._long = -0.546760142857143},
  [48] = { ._label = "45B Listing Sharon 7.5m", ._m5label = "45B\n\nListing\nSharon\n\n7.5m", BLUE_BUOY, ._lat = 51.4598098699702, ._long = -0.54670373432756},
  [49] = { ._label = "46N Plane 6m", ._m5label = "46N\n\nPlane\n\n6m", ._cat=NO_BUOY, ._lat = 51.459745, ._long = -0.546649},
  [50] = { ._label = "47P 6m", ._m5label = "47P 6m", ._cat=PLATFORM, ._lat = 51.459399, ._long = -0.546594},
  [51] = { ._label = "48N Holey Ship 4.5m", ._m5label = "48N\nHoley\nShip", ._cat=NO_BUOY, ._lat = 51.4594384444444, ._long = -0.5465238},
  [52] = { ._label = "49B Claymore 6.5m", ._m5label = "49B\n\nClay-\n   more\n\n6.5m", BLUE_BUOY, ._lat = 51.459634435324, ._long = -0.54646635372985},
  [53] = { ._label = "50aN Swim Through - no crates 6m", ._m5label = "50aN\nSwim\nThrough\nno\ncrates\n\n6m", ._cat=UNMARKED, ._lat = 51.45914367, ._long = -0.546032333},
  [54] = { ._label = "50bN Swim Through - mid 6m", ._m5label = "50bN\nSwim\nThrough\nmid 6m", ._cat=NO_BUOY, ._lat = 51.4591694, ._long = -0.545999},
  [55] = { ._label = "50cN Swim Through - crates 6m", ._m5label = "50cN\nSwim\nThrough\ncrates\n6m", ._cat=NO_BUOY, ._lat = 51.4592045, ._long = -0.545912625},
  [56] = { ._label = "51B Orca Van 5.5m", ._m5label = "51B\n\nOrca\nVan\n\n5.5m", BLUE_BUOY, ._lat = 51.4591431428571, ._long = -0.545936857142857},
  [57] = { ._label = "X01 Dinghy Boat", ._m5label = "X01\nDinghy\nBoat", ._cat=UNMARKED,._lat = 51.4601285, ._long = -0.5488505},
  [58] = { ._label = "X02 Quarry Machine in Reeds", ._m5label = "X02\nQuarry\nMachine\nReeds", ._cat=UNMARKED, ._lat = 51.460434, ._long = -0.548921},
  [59] = { ._label = "X03 Metal Grated Box", ._m5label = "X03\nMetal\nGrated\nBox", ._cat=UNMARKED, ._lat = 51.4599582857143, ._long = -0.547648571428571},
  [60] = { ._label = "X04 4 crates in a line", ._m5label = "X04\n4 x\nCrates\nLine", ._cat=UNMARKED, ._lat = 51.4599018571429, ._long = -0.547141285714286},
  [61] = { ._label = "X05 Lone crate", ._m5label = "X05\nLone\nCrate", ._cat=UNMARKED, ._lat = 51.4598467777778, ._long = -0.547212666666667},
  [62] = { ._label = "X06 Collapsed Metal", ._m5label = "X06\nCollapsed Metal", ._cat=UNMARKED, ._lat = 51.45967075, ._long = -0.547253125},
  [63] = { ._label = "X07 Boat with Chain Links", ._m5label = "X07\nChain\nLink\nBoat", ._cat=UNMARKED, ._lat = 51.4600385714286, ._long = -0.548724142857143},
  [64] = { ._label = "X08 Pot in a box", ._m5label = "X08\nPot In\nA Box", ._cat=UNMARKED, ._lat = 51.459940625, ._long = -0.54852025}, // by confined area
  [65] = { ._label = "X09 Seahorse Mid-Water", ._m5label = "X09\nSeahorse Midwater", ._cat=UNMARKED, ._lat = 51.4600703333333, ._long = -0.548645666666667},
  [66] = { ._label = "X10 Headless Nick", ._m5label = "X10\nHeadless\nNick", ._cat=UNMARKED, ._lat = 51.4600602857143, ._long = -0.548671714285714},
  [67] = { ._label = "X11 Headless Tom Reeds", ._m5label = "X11\nHeadless\nTom\nReeds", ._cat=UNMARKED, ._lat = 51.4600452, ._long = -0.5488188},
  [68] = { ._label = "X12 Cement Mixer", ._m5label = "X12\nCement\nMixer\n", ._cat=UNMARKED, ._lat = 51.46020025, ._long =	-0.5478815},
  [69] = { ._label = "X13 Tyre", ._m5label = "X13\nTyre", ._cat=UNMARKED, ._lat = 51.4600531428571, ._long = -0.548183857142857},
  [70] = { ._label = "X14 Roadworks Sign", ._m5label = "X14\nRoad\n  works'nSign", ._cat=UNMARKED, ._lat = 51.4595778, ._long = -0.547358},
  [71] = { ._label = "X15 Fireworks Launcher", ._m5label = "X15\nFirework\nLauncher", ._cat=UNMARKED, ._lat = 51.4599975, ._long = -0.5481015},
  [72] = { ._label = "X16 2 Buried Boats in Reeds", ._m5label = "X16\nBuried\nBoats\nIn\nWeeds", ._cat=UNMARKED, ._lat = 51.4593264705883, ._long = -0.5469361}, // By Disused exit, by fruit machine
  [73] = { ._label = "X17 Half Buried Solo Boat", ._m5label = "X17\nHalf\nBuried\nSolo\nBoat", ._cat=UNMARKED, ._lat = 51.4596635, ._long = -0.54706025},
  [74] = { ._label = "X18 Half Buried Bike", ._m5label = "X18\nHalf\nBuried\nBike", ._cat=UNMARKED, ._lat = 51.4600594210526, ._long = -0.547575473684211},
  [75] = { ._label = "X19 Desk with Keyboard", ._m5label = "X19\nPC\nDesk",._cat=UNMARKED, ._lat = 51.459924, ._long = -0.547615181818182},
  [76] = { ._label = "X20 La Mouette Boat", ._m5label = "X20\nLa\nMouette\nBoat", ._cat=UNMARKED, ._lat = 51.460740, ._long = -0.547713}, // By die hard taxi
  [77] = { ._label = "X21 Memorial Stone - Kit 7.5m", ._m5label = "X21\nMem\nStone\nKit\n7.5m", ._cat=UNMARKED, ._lat = 51.460993, ._long = -0.548006}, // Near die hard taxi
  [78] = { ._label = "X22 Fruit Machine 5.5m", ._m5label = "X22\nFruit\nMach\n5.5m", ._cat=UNMARKED, ._lat = 51.459353, ._long = -0.546939}, // By disused exit + 2 buried boats
  [79] = { ._label = "X23 Lone Crate 7m", ._m5label = "X23\nLone\nCrate\n7m", ._cat=UNMARKED, ._lat = 51.461249, ._long = -0.548688},
  [80] = { ._label = "X24 ? near plane 6m", ._m5label = "X24?\nnear\nplanen6m", ._cat=UNKNOWN, ._lat = 51.459784, ._long =-0.546550}, // Near Plane
  [81] = { ._label = "X25 Cotton Reel 3m", ._m5label = "X25\nCotton\nReel\n3m", ._cat=UNMARKED, ._lat = 51.4623163, ._long = -0.5494161 }, // near canoe
  [82] = { ._label = "X26 Dumpy Cylinder 6m", ._m5label = "X26\nDumpy\nCylinder\n6m",._cat=UNMARKED, ._lat = 51.4600631, ._long = -0.5480722},
  [83] = { ._label = "Z01 Cafe Jetty", ._m5label = "Z01\n\nCafe\nJetty", ._cat=JETTY, ._lat = 51.460015, ._long = -0.548316},
  [84] = { ._label = "Z02 Mid Jetty", ._m5label = "Z02\n\nMid\nJetty", ._cat=JETTY, ._lat = 51.459547, ._long = -0.547461},
  [85] = { ._label = "Z03 Old Jetty", ._m5label = "Z03\n\nOld\nJetty", ._cat=JETTY, ._lat = 51.459166, ._long = -0.546999333333333},

/*
  [86] = { ._label = "CN1 Canoe NW", ._m5label = "CN1\nCanoe NW", ._cat=UNMARKED, ._lat = 51.4621272, ._long = -0.5490348},
  [87] = { ._label = "CN2 Canoe N", ._m5label = "CN2\nCanoe N", ._cat=UNMARKED, ._lat = 51.4621644, ._long = -0.5489503},
  [88] = { ._label = "CN3 Canoe NE", ._m5label = "CN3\nCanoe NE", ._cat=UNMARKED, ._lat = 51.4621235, ._long = -0.5488664},
  [89] = { ._label = "CN4 Canoe E", ._m5label = "CN4\nCanoe E", ._cat=UNMARKED, ._lat = 51.4620654, ._long = -0.5488102},
  [90] = { ._label = "CN5 Canoe SE", ._m5label = "CN5\nCanoe SE", ._cat=UNMARKED, ._lat = 51.4620027, ._long = -0.5488524},
  [91] = { ._label = "CN6 Canoe S", ._m5label = "CN6\nCanoe S", ._cat=UNMARKED, ._lat = 51.4619701, ._long = -0.5489477},
  [92] = { ._label = "CN7 Canoe SW", ._m5label = "CN7\nCanoe SW", ._cat=UNMARKED, ._lat = 51.4619939, ._long = -0.5490341},
  [93] = { ._label = "CN8 Canoe W", ._m5label = "CN8\nCanoe W", ._cat=UNMARKED, ._lat = 51.4620666, ._long = -0.5490951},

  [94] = { ._label = "SS1 Sub W", ._m5label = "SS1\nSub W", ._cat=UNMARKED, ._lat = 51.4609559, ._long = -0.5492975},
  [95] = { ._label = "SS2 Sub NW", ._m5label = "SS2\nSub NW", ._cat=UNMARKED, ._lat =  51.461031, ._long = -0.5492317},
  [96] = { ._label = "SS3 Sub N", ._m5label = "SS3\nSub N", ._cat=UNMARKED, ._lat = 51.4610407, ._long = -0.5491586},
  [97] = { ._label = "SS4 Sub NE", ._m5label = "SS4\nSub NE", ._cat=UNMARKED, ._lat = 51.4610231, ._long = -0.5490675},
  [98] = { ._label = "SS5 Sub E", ._m5label = "SS5\nSub E", ._cat=UNMARKED, ._lat = 51.4609554, ._long = -0.5490171},
  [99] = { ._label = "SS6 Sub SE", ._m5label = "SS6\nSub SE", ._cat=UNMARKED, ._lat =  51.460884, ._long = -0.5490634},
  [100] = { ._label = "SS7 Sub S", ._m5label = "SS7\nSub S", ._cat=UNMARKED, ._lat = 51.4608669, ._long = -0.5491586},
  [101] = { ._label = "SS8 Sub SW", ._m5label = "SS8\nSub SW", ._cat=UNMARKED, ._lat = 51.4608861, ._long = -0.5492377},
*/
}};

