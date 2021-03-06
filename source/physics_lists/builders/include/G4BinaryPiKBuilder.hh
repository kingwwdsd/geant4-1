//
// ********************************************************************
// * License and Disclaimer                                           *
// *                                                                  *
// * The  Geant4 software  is  copyright of the Copyright Holders  of *
// * the Geant4 Collaboration.  It is provided  under  the terms  and *
// * conditions of the Geant4 Software License,  included in the file *
// * LICENSE and available at  http://cern.ch/geant4/license .  These *
// * include a list of copyright holders.                             *
// *                                                                  *
// * Neither the authors of this software system, nor their employing *
// * institutes,nor the agencies providing financial support for this *
// * work  make  any representation or  warranty, express or implied, *
// * regarding  this  software system or assume any liability for its *
// * use.  Please see the license in the file  LICENSE  and URL above *
// * for the full disclaimer and the limitation of liability.         *
// *                                                                  *
// * This  code  implementation is the result of  the  scientific and *
// * technical work of the GEANT4 collaboration.                      *
// * By using,  copying,  modifying or  distributing the software (or *
// * any work based  on the software)  you  agree  to acknowledge its *
// * use  in  resulting  scientific  publications,  and indicate your *
// * acceptance of all terms of the Geant4 Software license.          *
// ********************************************************************
//
// $Id: G4BinaryPiKBuilder.hh 103593 2017-04-19 08:10:21Z gcosmo $
//
//---------------------------------------------------------------------------
//
// ClassName:   G4BinaryPiKBuilder
//
// Author: 2002 H.P. Wellisch
//
// Modified:
// 30.03.2009 V.Ivanchenko create cross section by new
// 12.04.2017 A.Dotti move to new design with base class
//
//----------------------------------------------------------------------------
//
#ifndef G4BinaryPiKBuilder_h
#define G4BinaryPiKBuilder_h 1

#include "globals.hh"

#include "G4HadronElasticProcess.hh"
#include "G4HadronFissionProcess.hh"
#include "G4HadronCaptureProcess.hh"
#include "G4NeutronInelasticProcess.hh"
#include "G4VPiKBuilder.hh"

#include "G4PiNuclearCrossSection.hh"
#include "G4BinaryCascade.hh"   

class G4BinaryPiKBuilder : public G4VPiKBuilder
{
  public: 
    G4BinaryPiKBuilder();
    virtual ~G4BinaryPiKBuilder() {}

    virtual void Build(G4HadronElasticProcess *) final override {}
    virtual void Build(G4PionPlusInelasticProcess * aP) final override;
    virtual void Build(G4PionMinusInelasticProcess * aP) final override;
    virtual void Build(G4KaonPlusInelasticProcess *) final override {}
    virtual void Build(G4KaonMinusInelasticProcess *) final override {}
    virtual void Build(G4KaonZeroLInelasticProcess *) final override {}
    virtual void Build(G4KaonZeroSInelasticProcess *) final override {}
    
    virtual void SetMinEnergy(G4double aM) final override {theMin = aM;}
    virtual void SetMaxEnergy(G4double aM) final override {theMax = aM;}

    using G4VPiKBuilder::Build; //Prevent compiler warning

  private:
    G4PiNuclearCrossSection* thePiData;
    G4BinaryCascade * theModel;    
    G4double theMin;
    G4double theMax;

};

// 2002 by J.P. Wellisch

#endif

