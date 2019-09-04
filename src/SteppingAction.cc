#include "SteppingAction.hh"

#include "G4Event.hh"
#include "G4RunManager.hh"
#include "G4SystemOfUnits.hh"
#include "G4RunManager.hh"


SteppingAction::SteppingAction()
: G4UserSteppingAction()
{
}

SteppingAction::~SteppingAction()
{
}

void SteppingAction::UserSteppingAction(const G4Step* step)
{
	G4int eventID = G4RunManager::GetRunManager() -> GetCurrentEvent() -> GetEventID();
	G4int particleID = step -> GetTrack() -> GetParticleDefinition() -> GetPDGEncoding();
	G4int volumeID = step -> GetPreStepPoint() -> GetPhysicalVolume() -> GetCopyNo();
	G4double totalEdep = 1000*(step -> GetTotalEnergyDeposit());
	G4double KineticEnergy = 1000*(step -> GetTrack() -> GetKineticEnergy()); 
	

	G4AnalysisManager* analysisManager = G4AnalysisManager::Instance();
/*
// 6cluster type
// ringtype
        
	for(int i=1;i<5;i++)
//	for(int i=0;i<8;i++)
	{
		for(int j=5;j<8;j++)
//		for(int j=-1;j<2;j++)
		{
			for(int k=0;k<2;k++)
			{
				if(volumeID==10*i*j*(2*k-1))
//				if(volumeID==(200+(j+2)*10+(i+1)))

				{
					analysisManager -> FillNtupleIColumn(0, eventID);
					analysisManager -> FillNtupleIColumn(1, volumeID);
					analysisManager -> FillNtupleIColumn(2, particleID);
					analysisManager -> FillNtupleDColumn(3, totalEdep);
					analysisManager -> FillNtupleDColumn(4, KineticEnergy);
					analysisManager -> AddNtupleRow();
				}

			}
		}
	}

*/
//				for(int i=0;i<4;i++)
				{
				if(volumeID==200||volumeID==400)
				{
					analysisManager -> FillNtupleIColumn(0, eventID);
					analysisManager -> FillNtupleIColumn(1, volumeID);
					analysisManager -> FillNtupleIColumn(2, particleID);
					analysisManager -> FillNtupleDColumn(3, totalEdep);
					analysisManager -> FillNtupleDColumn(4, KineticEnergy);
					analysisManager -> AddNtupleRow();
				}}



}
