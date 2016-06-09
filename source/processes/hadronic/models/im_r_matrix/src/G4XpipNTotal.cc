//
// ********************************************************************
// * DISCLAIMER                                                       *
// *                                                                  *
// * The following disclaimer summarizes all the specific disclaimers *
// * of contributors to this software. The specific disclaimers,which *
// * govern, are listed with their locations in:                      *
// *   http://cern.ch/geant4/license                                  *
// *                                                                  *
// * Neither the authors of this software system, nor their employing *
// * institutes,nor the agencies providing financial support for this *
// * work  make  any representation or  warranty, express or implied, *
// * regarding  this  software system or assume any liability for its *
// * use.                                                             *
// *                                                                  *
// * This  code  implementation is the  intellectual property  of the *
// * GEANT4 collaboration.                                            *
// * By copying,  distributing  or modifying the Program (or any work *
// * based  on  the Program)  you indicate  your  acceptance of  this *
// * statement, and all its terms.                                    *
// ********************************************************************
//
#include "G4XpipNTotal.hh"
#include <math.h>

G4XpipNTotal::
 G4XpipNTotal()
 {
   std::pair<double,double> it;
   it.first=1105.46; it.second= 6.4;  theLowEData.push_back(it);
   it.first=1133.28; it.second= 18.0; theLowEData.push_back(it);
   it.first=1165.12; it.second= 66.0; theLowEData.push_back(it);
   it.first=1198.8;  it.second= 160.; theLowEData.push_back(it);
   it.first=1212.51; it.second= 199.; theLowEData.push_back(it);
   it.first=1233.18; it.second= 195.; theLowEData.push_back(it);
   it.first=1301.86; it.second= 73.8; theLowEData.push_back(it);
   it.first=1368.93; it.second= 35.0; theLowEData.push_back(it);
   it.first=1433.81; it.second= 22.0; theLowEData.push_back(it);
   it.first=1496.42; it.second= 15.0; theLowEData.push_back(it);
   it.first=1556.84; it.second= 15.2; theLowEData.push_back(it);
   it.first=1615.21; it.second= 19.4; theLowEData.push_back(it);
   it.first=1671.7;  it.second= 25.;  theLowEData.push_back(it);
   it.first=1726.44; it.second= 26.;  theLowEData.push_back(it);
   it.first=1779.57; it.second= 30.;  theLowEData.push_back(it);
   it.first=1881.49; it.second= 40.;  theLowEData.push_back(it);
   it.first=1930.49; it.second= 40.;  theLowEData.push_back(it);
   it.first=2070.69; it.second= 30.;  theLowEData.push_back(it);
   it.first=2202.11; it.second= 29.;  theLowEData.push_back(it);
   it.first=2326.19; it.second= 30.7; theLowEData.push_back(it);
   it.first=2405.38; it.second= 30.7; theLowEData.push_back(it);
   it.first=2733.67; it.second= 28.3; theLowEData.push_back(it);
   it.first=3207.21; it.second= 26.5; theLowEData.push_back(it);
   it.first=4434.76; it.second= 25.0; theLowEData.push_back(it);
 } 

G4double G4XpipNTotal::
 CrossSection(const G4KineticTrack& trk1, const G4KineticTrack& trk2) const
 {
   G4double sqrts = (trk1.Get4Momentum() + trk2.Get4Momentum()).mag();
   if(sqrts > theLowEData.back().first/MeV) return thePDGData.CrossSection(trk1, trk2);
   G4double result = 0;
   size_t i(0), it(0);
   if(sqrts<theLowEData[0].first) return 0;
   for(i=0; i<theLowEData.size(); i++)
   {
     if(theLowEData[i].first/MeV>sqrts) break;
     it = i;
   }
   G4double x1 = std::log(theLowEData[it].first);
   G4double x2 = std::log(theLowEData[it+1].first);
   G4double y1 = std::log(theLowEData[it].second);
   G4double y2 = std::log(theLowEData[it+1].second);
   G4double x = std::log(sqrts);
   G4double y = y1+(x-x1)*(y2-y1)/(x2-x1);
   result = std::exp(y);
   return result*millibarn;
 }