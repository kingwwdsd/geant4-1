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
//
// $Id: AnaEx01SteppingVerbose.hh,v 1.3 2003/06/20 14:55:45 gbarrand Exp $
// GEANT4 tag $Name: geant4-05-02 $
//
//  
//---------------------------------------------------------------
//
// AnaEx01SteppingVerbose.hh
//
// Description:
//   This class manages the verbose outputs in G4SteppingManager. 
//   It inherits from G4SteppingVerbose   
//
//---------------------------------------------------------------

class AnaEx01SteppingVerbose;

#ifndef AnaEx01SteppingVerbose_h
#define AnaEx01SteppingVerbose_h 1

#include "G4SteppingVerbose.hh"

class AnaEx01SteppingVerbose : public G4SteppingVerbose {
public:   
// Constructor/Destructor
  AnaEx01SteppingVerbose();
 ~AnaEx01SteppingVerbose();
//
  void StepInfo();
  void TrackingStarted();
//


};

#endif