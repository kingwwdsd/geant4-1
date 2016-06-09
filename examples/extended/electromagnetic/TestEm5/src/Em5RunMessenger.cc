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
// $Id: Em5RunMessenger.cc,v 1.8 2003/05/30 10:28:05 urban Exp $
// GEANT4 tag $Name: geant4-05-02 $
//
// 

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......
//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

#include "Em5RunMessenger.hh"

#include "Em5RunAction.hh"
#include "G4UIdirectory.hh"
#include "G4UIcmdWithAnInteger.hh"
#include "G4UIcmdWithADoubleAndUnit.hh"
#include "G4UIcmdWithADouble.hh"
#include "G4UIcmdWithAString.hh"
#include "G4ios.hh"
#include "globals.hh"

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

Em5RunMessenger::Em5RunMessenger(Em5RunAction* RA)
:runAction (RA)
{
  plotDir = new G4UIdirectory("/testem/plots/");
  plotDir->SetGuidance("plot control");

  sethistNameCmd = new G4UIcmdWithAString("/testem/plots/sethistName",this);
  sethistNameCmd->SetGuidance("set name for the histogram file"); 

  setnbinStepCmd = new G4UIcmdWithAnInteger("/testem/plots/setnbinStep",this);
  setnbinStepCmd->SetGuidance("set nb of bins in #step plot");
  setnbinStepCmd->SetParameterName("nbinStep",false);

  setSteplowCmd = new G4UIcmdWithADouble("/testem/plots/setSteplow",this);
  setSteplowCmd->SetGuidance("set lower limit for #step plot ");
  setSteplowCmd->SetParameterName("Steplow",false);

  setStephighCmd = new G4UIcmdWithADouble("/testem/plots/setStephigh",this);
  setStephighCmd->SetGuidance("set upper limit for #step plot ");
  setStephighCmd->SetParameterName("Stephigh",false);

  setnbinEnCmd = new G4UIcmdWithAnInteger("/testem/plots/setnbinEn",this);
  setnbinEnCmd->SetGuidance("set nb of bins in Edep plot");
  setnbinEnCmd->SetParameterName("nbinE",false);

  setEnlowCmd = new G4UIcmdWithADoubleAndUnit("/testem/plots/setEnlow",this);
  setEnlowCmd->SetGuidance("set lower limit for Edep plot ");
  setEnlowCmd->SetParameterName("Elow",false);
  setEnlowCmd->SetUnitCategory("Energy");
  
  setEnhighCmd = new G4UIcmdWithADoubleAndUnit("/testem/plots/setEnhigh",this);
  setEnhighCmd->SetGuidance("set upper limit for Edep plot ");
  setEnhighCmd->SetParameterName("Ehigh",false);
  setEnhighCmd->SetUnitCategory("Energy");

  setnbinGammaCmd = new G4UIcmdWithAnInteger("/testem/plots/setnbinGamma",this);
  setnbinGammaCmd->SetGuidance("set nb of bins in gamma spectrum plot");
  setnbinGammaCmd->SetParameterName("nbinGamma",false);

  setElowGammaCmd = new G4UIcmdWithADoubleAndUnit("/testem/plots/setElowGamma",this);
  setElowGammaCmd->SetGuidance("set lower limit for gamma spectrum plot ");
  setElowGammaCmd->SetParameterName("ElowGamma",false);
  setElowGammaCmd->SetUnitCategory("Energy");

  setEhighGammaCmd = new G4UIcmdWithADoubleAndUnit("/testem/plots/setEhighGamma",this);
  setEhighGammaCmd->SetGuidance("set upper limit for gamma spectrum plot ");
  setEhighGammaCmd->SetParameterName("EhighGamma",false);
  setEhighGammaCmd->SetUnitCategory("Energy");

  setnbinTtCmd = new G4UIcmdWithAnInteger("/testem/plots/setnbinTt",this);
  setnbinTtCmd->SetGuidance("set nb of bins in Etransmitted plot");
  setnbinTtCmd->SetParameterName("nbinTt",false);

  setTtlowCmd = new G4UIcmdWithADoubleAndUnit("/testem/plots/setTtlow",this);
  setTtlowCmd->SetGuidance("set lower limit for Etransmitted plot ");
  setTtlowCmd->SetParameterName("Ttlow",false);

  setTthighCmd = new G4UIcmdWithADoubleAndUnit("/testem/plots/setTthigh",this);
  setTthighCmd->SetGuidance("set upper limit for Etransmitted plot ");
  setTthighCmd->SetParameterName("Tthigh",false);

  setnbinTbCmd = new G4UIcmdWithAnInteger("/testem/plots/setnbinTb",this);
  setnbinTbCmd->SetGuidance("set nb of bins in Ebackscattering plot");
  setnbinTbCmd->SetParameterName("nbinTb",false);

  setTblowCmd = new G4UIcmdWithADoubleAndUnit("/testem/plots/setTblow",this);
  setTblowCmd->SetGuidance("set lower limit for Ebackscattered plot ");
  setTblowCmd->SetParameterName("Tblow",false);

  setTbhighCmd = new G4UIcmdWithADoubleAndUnit("/testem/plots/setTbhigh",this);
  setTbhighCmd->SetGuidance("set upper limit for Ebackscattered plot ");
  setTbhighCmd->SetParameterName("Tbhigh",false);

  setnbinTsecCmd = new G4UIcmdWithAnInteger("/testem/plots/setnbinTsec",this);
  setnbinTsecCmd->SetGuidance("set nb of bins in charged Tsecondary plot");
  setnbinTsecCmd->SetParameterName("nbinTsec",false);

  setTseclowCmd = new G4UIcmdWithADoubleAndUnit("/testem/plots/setTseclow",this);
  setTseclowCmd->SetGuidance("set lower limit for charged Tsecondary plot ");
  setTseclowCmd->SetParameterName("Tseclow",false);

  setTsechighCmd = new G4UIcmdWithADoubleAndUnit("/testem/plots/setTsechigh",this);
  setTsechighCmd->SetGuidance("set upper limit for charged Tsecondary plot ");
  setTsechighCmd->SetParameterName("Tsechigh",false);

  setnbinRCmd = new G4UIcmdWithAnInteger("/testem/plots/setnbinR",this);
  setnbinRCmd->SetGuidance("set nb of bins in R plot");
  setnbinRCmd->SetParameterName("nbinR",false);

  setRlowCmd = new G4UIcmdWithADoubleAndUnit("/testem/plots/setRlow",this);
  setRlowCmd->SetGuidance("set lower limit for R plot ");
  setRlowCmd->SetParameterName("Rlow",false);

  setRhighCmd = new G4UIcmdWithADoubleAndUnit("/testem/plots/setRhigh",this);
  setRhighCmd->SetGuidance("set upper limit for R plot ");
  setRhighCmd->SetParameterName("Rhigh",false);

  setnbinzvertexCmd = new G4UIcmdWithAnInteger("/testem/plots/setnbinzvertex",this);
  setnbinzvertexCmd->SetGuidance("set nb of bins in Z vertex plot");
  setnbinzvertexCmd->SetParameterName("nbinZ",false);

  setzlowCmd = new G4UIcmdWithADoubleAndUnit("/testem/plots/setzlow",this);
  setzlowCmd->SetGuidance("set lower limit for Z vertex plot ");
  setzlowCmd->SetParameterName("zlow",false);

  setzhighCmd = new G4UIcmdWithADoubleAndUnit("/testem/plots/setzhigh",this);
  setzhighCmd->SetGuidance("set upper limit for Z vertex plot ");
  setzhighCmd->SetParameterName("zhigh",false);

  setnbinThCmd = new G4UIcmdWithAnInteger("/testem/plots/setnbinTh",this);
  setnbinThCmd->SetGuidance("set nb of bins in Theta transmitted plot");
  setnbinThCmd->SetParameterName("nbinTh",false);

  setThlowCmd = new G4UIcmdWithADoubleAndUnit("/testem/plots/setThlow",this);
  setThlowCmd->SetGuidance("set lower limit for Theta transmitted plot ");
  setThlowCmd->SetParameterName("Thlow",false);

  setThhighCmd = new G4UIcmdWithADoubleAndUnit("/testem/plots/setThhigh",this);
  setThhighCmd->SetGuidance("set upper limit for Theta transmitted plot ");
  setThhighCmd->SetParameterName("Thhigh",false);

  setnbinThprojCmd = new G4UIcmdWithAnInteger("/testem/plots/setnbinThproj",this);
  setnbinThprojCmd->SetGuidance("set nb of bins in Thetaproj transmitted plot");
  setnbinThprojCmd->SetParameterName("nbinThproj",false);

  setThlowprojCmd = new G4UIcmdWithADoubleAndUnit("/testem/plots/setThlowproj",this);
  setThlowprojCmd->SetGuidance("set lower limit for Thetaproj transmitted plot ");
  setThlowprojCmd->SetParameterName("Thlowproj",false);

  setThhighprojCmd = new G4UIcmdWithADoubleAndUnit("/testem/plots/setThhighproj",this);
  setThhighprojCmd->SetGuidance("set upper limit for Thetaproj transmitted plot ");
  setThhighprojCmd->SetParameterName("Thhighproj",false);

  setnbinThbackCmd = new G4UIcmdWithAnInteger("/testem/plots/setnbinThback",this);
  setnbinThbackCmd->SetGuidance("set nb of bins in backscattering Theta plot");
  setnbinThbackCmd->SetParameterName("nbinThback",false);

  setThlowbackCmd = new G4UIcmdWithADoubleAndUnit("/testem/plots/setThlowback",this);
  setThlowbackCmd->SetGuidance("set lower limit for backscattering Theta plot");
  setThlowbackCmd->SetParameterName("Thlowback",false);

  setThhighbackCmd = new G4UIcmdWithADoubleAndUnit("/testem/plots/setThhighback",this);
  setThhighbackCmd->SetGuidance("set upper limit for backscattering Teta plot");
  setThhighbackCmd->SetParameterName("Thhighback",false);
}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

Em5RunMessenger::~Em5RunMessenger()
{
  delete sethistNameCmd;

  delete setnbinStepCmd;
  delete setSteplowCmd;
  delete setStephighCmd;

  delete setnbinEnCmd;
  delete setEnlowCmd;
  delete setEnhighCmd;

  delete setnbinGammaCmd;
  delete setElowGammaCmd;
  delete setEhighGammaCmd;

  delete setnbinTtCmd;
  delete setTtlowCmd;
  delete setTthighCmd;

  delete setnbinTbCmd;
  delete setTblowCmd;
  delete setTbhighCmd;

  delete setnbinTsecCmd;
  delete setTseclowCmd;
  delete setTsechighCmd;

  delete setnbinRCmd;
  delete setRlowCmd;
  delete setRhighCmd;

  delete setnbinzvertexCmd;
  delete setzlowCmd;
  delete setzhighCmd;

  delete setnbinThCmd;
  delete setThlowCmd;
  delete setThhighCmd;

  delete setnbinThprojCmd;
  delete setThlowprojCmd;
  delete setThhighprojCmd;
	
  delete setnbinThbackCmd;
  delete setThlowbackCmd;
  delete setThhighbackCmd;

  delete plotDir;  
}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

void Em5RunMessenger::SetNewValue(G4UIcommand* command,G4String newValues)
{
  if( command == sethistNameCmd)
    runAction
    ->SethistName(newValues) ;
    
  if( command == setnbinStepCmd)
    runAction
    ->SetnbinStep(setnbinStepCmd->GetNewIntValue(newValues));

  if( command == setSteplowCmd)
    runAction
    ->SetSteplow( setSteplowCmd->GetNewDoubleValue(newValues));

  if( command == setStephighCmd)
    runAction
    ->SetStephigh( setStephighCmd->GetNewDoubleValue(newValues));

  if( command == setnbinEnCmd)
    runAction
    ->SetnbinEn(setnbinEnCmd->GetNewIntValue(newValues));

  if( command == setEnlowCmd)
    runAction
    ->SetEnlow( setEnlowCmd->GetNewDoubleValue(newValues));

  if( command == setEnhighCmd)
    runAction
    ->SetEnhigh( setEnhighCmd->GetNewDoubleValue(newValues));

  if( command == setnbinGammaCmd)
    runAction
    ->SetnbinGamma(setnbinGammaCmd->GetNewIntValue(newValues));

  if( command == setElowGammaCmd)
    runAction
    ->SetElowGamma( setElowGammaCmd->GetNewDoubleValue(newValues));

  if( command == setEhighGammaCmd)
    runAction
    ->SetEhighGamma( setEhighGammaCmd->GetNewDoubleValue(newValues));

  if( command == setnbinTtCmd)
    runAction
    ->SetnbinTt(setnbinTtCmd->GetNewIntValue(newValues));

  if( command == setTtlowCmd)
    runAction
    ->SetTtlow( setTtlowCmd->GetNewDoubleValue(newValues));

  if( command == setTthighCmd)
    runAction
    ->SetTthigh( setTthighCmd->GetNewDoubleValue(newValues));

  if( command == setnbinTbCmd)
    runAction
    ->SetnbinTb(setnbinTbCmd->GetNewIntValue(newValues));

  if( command == setTblowCmd)
    runAction
    ->SetTblow( setTblowCmd->GetNewDoubleValue(newValues));

  if( command == setTbhighCmd)
    runAction
    ->SetTbhigh( setTbhighCmd->GetNewDoubleValue(newValues));

  if( command == setnbinTsecCmd)
    runAction
    ->SetnbinTsec(setnbinTsecCmd->GetNewIntValue(newValues));

  if( command == setTseclowCmd)
    runAction
    ->SetTseclow( setTseclowCmd->GetNewDoubleValue(newValues));

  if( command == setTsechighCmd)
    runAction
    ->SetTsechigh( setTsechighCmd->GetNewDoubleValue(newValues));

  if( command == setnbinRCmd)
    runAction
    ->SetnbinR(setnbinRCmd->GetNewIntValue(newValues));

  if( command == setRlowCmd)
    runAction
    ->SetRlow( setRlowCmd->GetNewDoubleValue(newValues));

  if( command == setRhighCmd)
    runAction
    ->SetRhigh( setRhighCmd->GetNewDoubleValue(newValues));

  if( command == setnbinzvertexCmd)
    runAction
    ->Setnbinzvertex(setnbinzvertexCmd->GetNewIntValue(newValues));

  if( command == setzlowCmd)
    runAction
    ->Setzlow( setzlowCmd->GetNewDoubleValue(newValues));

  if( command == setzhighCmd)
    runAction
    ->Setzhigh( setzhighCmd->GetNewDoubleValue(newValues));

  if( command == setnbinThCmd)
    runAction
    ->SetnbinTh(setnbinThCmd->GetNewIntValue(newValues));

  if( command == setThlowCmd)
    runAction
    ->SetThlow( setThlowCmd->GetNewDoubleValue(newValues));

  if( command == setThhighCmd)
    runAction
    ->SetThhigh( setThhighCmd->GetNewDoubleValue(newValues));

  if( command == setnbinThprojCmd)
    runAction
    ->SetnbinThproj(setnbinThprojCmd->GetNewIntValue(newValues));

  if( command == setThlowprojCmd)
    runAction
    ->SetThlowproj( setThlowprojCmd->GetNewDoubleValue(newValues));

  if( command == setThhighprojCmd)
    runAction
    ->SetThhighproj( setThhighprojCmd->GetNewDoubleValue(newValues));

  if( command == setnbinThbackCmd)
    runAction
    ->SetnbinThBack(setnbinThbackCmd->GetNewIntValue(newValues));

  if( command == setThlowbackCmd)
    runAction
    ->SetThlowBack( setThlowbackCmd->GetNewDoubleValue(newValues));

  if( command == setThhighbackCmd)
    runAction
    ->SetThhighBack( setThhighbackCmd->GetNewDoubleValue(newValues));
}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

   