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
/// \file PrimaryGeneratorAction.cc
/// \brief Implementation of the PrimaryGeneratorAction class
//
// $Id$
// 
//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......
//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......
#include "PrimaryGeneratorAction.hh"

#include "G4Event.hh"
#include "G4ParticleTable.hh"
#include "G4IonTable.hh"
#include "G4ParticleDefinition.hh"
#include "G4Geantino.hh"
#include "G4SystemOfUnits.hh"
#include "Randomize.hh"
//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

PrimaryGeneratorAction::PrimaryGeneratorAction()
 : G4VUserPrimaryGeneratorAction()
 //  fParticleGun(0)

{

 G4int n_particle = 1;
  
	fParticleGun  = new G4ParticleGun(n_particle);
//-------감마랜덤
/*
G4ParticleTable* particleTable = G4ParticleTable::GetParticleTable();
G4String particleName;
G4ParticleDefinition* particle  = particleTable -> FindParticle(particleName = "gamma");
fParticleGun -> SetParticleDefinition(particle);
*/

}


//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

PrimaryGeneratorAction::~PrimaryGeneratorAction()
{
  delete fParticleGun;
}




//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

void PrimaryGeneratorAction::GeneratePrimaries(G4Event* anEvent)
{

//--------감마랜덤
/* 
  G4double phi = CLHEP::pi*G4UniformRand();
  G4double theta = CLHEP::pi*G4UniformRand();
  fParticleGun -> SetParticleMomentumDirection(G4ThreeVector(std::sin(theta)*std::cos(phi),std::sin(theta)*std::sin(phi), std::cos(theta)));
  */
//-----------	






//--------------------------감마랜덤--------------------
//	G4int seed = rand()%12;
	/*
if(seed==0)
{fParticleGun->SetParticleEnergy(100*keV);
	fParticleGun -> GeneratePrimaryVertex(anEvent);}
else if(seed==1)
{fParticleGun->SetParticleEnergy(200*keV);
	fParticleGun -> GeneratePrimaryVertex(anEvent);}
else if(seed==2)
{fParticleGun->SetParticleEnergy(300*keV);
	fParticleGun -> GeneratePrimaryVertex(anEvent);}
else if(seed==3)
{fParticleGun->SetParticleEnergy(400*keV);

	fParticleGun -> GeneratePrimaryVertex(anEvent);}
else if(seed==4)
{fParticleGun->SetParticleEnergy(500*keV);
	fParticleGun -> GeneratePrimaryVertex(anEvent);}
else if(seed==5)
{fParticleGun->SetParticleEnergy(600*keV);
	fParticleGun -> GeneratePrimaryVertex(anEvent);}
	
else if(seed==6)
{fParticleGun->SetParticleEnergy(700*keV);
	fParticleGun -> GeneratePrimaryVertex(anEvent);}
else if(seed==7)
{fParticleGun->SetParticleEnergy(800*keV);
	fParticleGun -> GeneratePrimaryVertex(anEvent);}
else if(seed==8)
{fParticleGun->SetParticleEnergy(900*keV);
	fParticleGun -> GeneratePrimaryVertex(anEvent);}
else if(seed==9)
{fParticleGun->SetParticleEnergy(1000*keV);
	fParticleGun -> GeneratePrimaryVertex(anEvent);}
else if(seed==10)
{fParticleGun->SetParticleEnergy(1500*keV);
	fParticleGun -> GeneratePrimaryVertex(anEvent);}
else if(seed==11)
{fParticleGun->SetParticleEnergy(2000*keV);
	fParticleGun -> GeneratePrimaryVertex(anEvent);}
	*/
//--------------------------------------------


	G4int seed = rand()%300;
        G4int seed2 = rand()%143;
        G4int seed3 = rand()%143;
        G4int seed4 = rand()%143;
        G4int seed5 = rand()%143;
/*	
	if (seed<100)           
		{                       
			fParticleGun->SetParticlePosition(G4ThreeVector(0.*mm,0.*mm,0.*mm));
			fParticleGun->SetParticleMomentumDirection(G4ThreeVector(0.,0.,1.));

			G4int Z = 63, A = 152;                
			G4double ionCharge   = 0.*eplus;
			G4double excitEnergy = 0.*keV;       

			G4ParticleDefinition* ion
				= G4IonTable::GetIonTable()->GetIon(Z,A,excitEnergy);
			fParticleGun->SetParticleDefinition(ion);
			fParticleGun->SetParticleCharge(ionCharge);
			fParticleGun->GeneratePrimaryVertex(anEvent);
		}

*/	
	
	
/*
	if (seed<300)
        {
                fParticleGun->SetParticlePosition(G4ThreeVector(0.*mm,0.*mm,0.*mm));
                fParticleGun->SetParticleMomentumDirection(G4ThreeVector(0.,0.,1.));

                        G4int Z = 27, A = 60;
                        G4double ionCharge   = 0.*eplus;
                        G4double excitEnergy = 0.*keV;

                        G4ParticleDefinition* ion
                                = G4IonTable::GetIonTable()->GetIon(Z,A,excitEnergy);
                        fParticleGun->SetParticleDefinition(ion);
                        fParticleGun->SetParticleCharge(ionCharge);

                        fParticleGun->GeneratePrimaryVertex(anEvent);
        }
	*/
/*
        {
                fParticleGun->SetParticlePosition(G4ThreeVector(0.*mm,0.*mm,0.*mm));
                fParticleGun->SetParticleMomentumDirection(G4ThreeVector(0.,0.,1.));

                        G4int Z = 55, A =137;
                        G4double ionCharge   = 0.*eplus;
                        G4double excitEnergy = 0.*keV;

                        G4ParticleDefinition* ion
                                = G4IonTable::GetIonTable()->GetIon(Z,A,excitEnergy);
                        fParticleGun->SetParticleDefinition(ion);
                        fParticleGun->SetParticleCharge(ionCharge);

                        fParticleGun->GeneratePrimaryVertex(anEvent);
        }
	*/
/*
	if (seed<98)
        {
                fParticleGun->SetParticlePosition(G4ThreeVector(0.*mm,0.*mm,0.*mm));
                fParticleGun->SetParticleMomentumDirection(G4ThreeVector(0.,0.,1.));

                        G4int Z = 56, A = 133;
                        G4double ionCharge   = 0.*eplus;
                        G4double excitEnergy = 0.*keV;

                        G4ParticleDefinition* ion
                                = G4IonTable::GetIonTable()->GetIon(Z,A,excitEnergy);
                        fParticleGun->SetParticleDefinition(ion);
                        fParticleGun->SetParticleCharge(ionCharge);

                        fParticleGun->GeneratePrimaryVertex(anEvent);
        }
	if (seed<98)
*/	
/*
	{
		fParticleGun->SetParticlePosition(G4ThreeVector(0.*mm,0.*mm,0.*mm));
		fParticleGun->SetParticleMomentumDirection(G4ThreeVector(0.,0.,1.));          

			G4int Z = 11, A = 22;
			G4double ionCharge   = 0.*eplus;
			G4double excitEnergy = 0.*keV;

			G4ParticleDefinition* ion
				= G4IonTable::GetIonTable()->GetIon(Z,A,excitEnergy);
			fParticleGun->SetParticleDefinition(ion);
			fParticleGun->SetParticleCharge(ionCharge);
			fParticleGun->GeneratePrimaryVertex(anEvent);

	}
*/
	if( seed<300)
        {
                G4double theta = 2*CLHEP::pi*G4UniformRand();
                G4double radii = 19.05*G4UniformRand();
                G4double height = 38.1*G4UniformRand();
                        fParticleGun->SetParticlePosition(G4ThreeVector((radii*std::cos(theta))*mm,radii*std::sin(theta)*mm,(height+25+0.5)*mm));

                        fParticleGun->SetParticleMomentumDirection(G4ThreeVector(1.,0.,0.));

                                G4int Z = 57, A = 138;
                        G4double ionCharge   = 0.*eplus;
                        G4double excitEnergy = 0.*keV;

                         G4ParticleDefinition* ion    = G4IonTable::GetIonTable()->GetIon(Z,A,excitEnergy);
                        fParticleGun->SetParticleDefinition(ion);
                        fParticleGun->SetParticleCharge(ionCharge);

                        fParticleGun->GeneratePrimaryVertex(anEvent);
        }

        if(seed<300)
        {
                G4double theta = 2*CLHEP::pi*G4UniformRand();
                G4double radii = 19.05*G4UniformRand();
                G4double height = 38.1*G4UniformRand();
                fParticleGun->SetParticlePosition(G4ThreeVector((radii*std::cos(theta))*mm,(radii*std::sin(theta))*mm,-(height+25+0.5)*mm));

                fParticleGun->SetParticleMomentumDirection(G4ThreeVector(1.,0.,0.));

                         G4int Z = 57, A = 138;
                        G4double ionCharge   = 0.*eplus;
                        G4double excitEnergy = 0.*keV;

                         G4ParticleDefinition* ion    = G4IonTable::GetIonTable()->GetIon(Z,A,excitEnergy);
                        fParticleGun->SetParticleDefinition(ion);
                        fParticleGun->SetParticleCharge(ionCharge);

                        fParticleGun->GeneratePrimaryVertex(anEvent);
	}
/*	
	if( seed2<1)
        {
                G4double theta = 2*CLHEP::pi*G4UniformRand();
                G4double radii = 19.05*G4UniformRand();
                G4double height = 38.1*G4UniformRand();
                        fParticleGun->SetParticlePosition(G4ThreeVector((radii*std::cos(theta)+44.5/2)*mm,radii*std::sin(theta)*mm,(height+50)*mm).rotate(1,0,0));

                        fParticleGun->SetParticleMomentumDirection(G4ThreeVector(1.,0.,0.));

                                G4int Z = 57, A = 138;
                        G4double ionCharge   = 0.*eplus;
                        G4double excitEnergy = 0.*keV;

                         G4ParticleDefinition* ion    = G4IonTable::GetIonTable()->GetIon(Z,A,excitEnergy);
                        fParticleGun->SetParticleDefinition(ion);
                        fParticleGun->SetParticleCharge(ionCharge);

                        fParticleGun->GeneratePrimaryVertex(anEvent);
        }

        if(seed3<1)
        {
                G4double theta = 2*CLHEP::pi*G4UniformRand();
                G4double radii = 19.05*G4UniformRand();
                G4double height = 38.1*G4UniformRand();
                fParticleGun->SetParticlePosition(G4ThreeVector((radii*std::cos(theta)-44.5/2)*mm,(radii*std::sin(theta)+44.5*sqrt(3)/2)*mm,(height+50)*mm));

                fParticleGun->SetParticleMomentumDirection(G4ThreeVector(1.,0.,0.));

                         G4int Z = 57, A = 138;
                        G4double ionCharge   = 0.*eplus;
                        G4double excitEnergy = 0.*keV;

                         G4ParticleDefinition* ion    = G4IonTable::GetIonTable()->GetIon(Z,A,excitEnergy);
                        fParticleGun->SetParticleDefinition(ion);
                        fParticleGun->SetParticleCharge(ionCharge);

                        fParticleGun->GeneratePrimaryVertex(anEvent);
	}
	if( seed4<1)
	{
		G4double theta = 2*CLHEP::pi*G4UniformRand();
		G4double radii = 19.05*G4UniformRand();
		G4double height = 38.1*G4UniformRand();
		fParticleGun->SetParticlePosition(G4ThreeVector(radii*std::cos(theta)*mm,(radii*std::sin(theta)+44.5/2*sqrt(3))*mm,(height+50)*mm));
		fParticleGun->SetParticleMomentumDirection(G4ThreeVector(1.,0.,0.));
		G4int Z = 57, A = 138;
		G4double ionCharge   = 0.*eplus;
		G4double excitEnergy = 0.*keV;
		G4ParticleDefinition* ion    = G4IonTable::GetIonTable()->GetIon(Z,A,excitEnergy);
		fParticleGun->SetParticleDefinition(ion);
		fParticleGun->SetParticleCharge(ionCharge);
		fParticleGun->GeneratePrimaryVertex(anEvent);
	}
	  if( seed5<1)
	  {
		  G4double theta = 2*CLHEP::pi*G4UniformRand();
		  G4double radii = 19.05*G4UniformRand();
		  G4double height = 38.1*G4UniformRand();
		  fParticleGun->SetParticlePosition(G4ThreeVector(radii*std::cos(theta)*mm,(radii*std::sin(theta)-44.5/2*sqrt(3))*mm,(height+50)*mm));
		  fParticleGun->SetParticleMomentumDirection(G4ThreeVector(1.,0.,0.));
		  G4int Z = 57, A = 138;
		  G4double ionCharge   = 0.*eplus;
		  G4double excitEnergy = 0.*keV;
		  G4ParticleDefinition* ion    = G4IonTable::GetIonTable()->GetIon(Z,A,excitEnergy);
		  fParticleGun->SetParticleDefinition(ion);
		  fParticleGun->SetParticleCharge(ionCharge);
		  fParticleGun->GeneratePrimaryVertex(anEvent);
	  }
*/



	
	//create vertex
	//   

}
//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......
