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
// $Id: cadex.cc,v 1.1 2002/06/20 10:00:54 gcosmo Exp $
// GEANT4 tag $Name: geant4-05-02 $
// ------------------------------------------------------------

#include "CadDetectorConstruction.hh"
#include "CadRunAction.hh"
#include "CadPrimaryGeneratorAction.hh"
#include "CadPhysicsList.hh"

#ifdef G4VIS_USE
  #include "CadVisManager.hh"
#endif

#include "G4RunManager.hh"
#include "G4UImanager.hh"

#if defined(G4UI_USE_XM)
  #include "G4UIXm.hh"
#elif defined(G4UI_USE_XAW)
  #include "G4UIXaw.hh"
#else
  #include "G4UIterminal.hh"
#endif

int main(int argc, char** argv)
{
  // Set the default random engine to RanecuEngine
  RanecuEngine defaultEngine;
  HepRandom::setTheEngine(&defaultEngine);

  // Run manager
  G4RunManager * runManager = new G4RunManager;

  // UserInitialization classes
  runManager->SetUserInitialization(new CadDetectorConstruction);
  runManager->SetUserInitialization(new CadPhysicsList);

  // Visualization manager
  #if defined(G4VIS_USE)
    G4VisManager* visManager = new CadVisManager;
    visManager->Initialize();
  #endif

  // UserAction classes
  runManager->SetUserAction(new CadRunAction);
  runManager->SetUserAction(new CadPrimaryGeneratorAction);

  // User interactions
  // Define (G)UI GAG for interactive mode
  if(argc==1)
  {
    // G4UIterminal is a (dumb) terminal
    #if defined(G4UI_USE_XM)
      G4UIsession * session = new G4UIXm(argc,argv);
    #elif defined(G4UI_USE_XAW)
      G4UIsession * session = new G4UIXaw(argc,argv);
    #else
      G4UIsession * session = new G4UIterminal;
    #endif
    session->SessionStart();
    delete session;
  }
  else
  // Batch mode
  {
    G4UImanager * UI = G4UImanager::GetUIpointer();
    G4String command = "/control/execute ";
    G4String fileName = argv[1];
    UI->ApplyCommand(command+fileName);
  }

  // Job termination
  #if defined(G4VIS_USE)
    delete visManager;
  #endif
  delete runManager;

  return 0;
}