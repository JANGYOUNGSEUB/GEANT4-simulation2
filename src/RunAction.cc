#include "RunAction.hh"


RunAction::RunAction()
: G4UserRunAction()
{
}

RunAction::~RunAction()
{
  delete G4AnalysisManager::Instance();
}

void RunAction::BeginOfRunAction(const G4Run*)
{
  G4AnalysisManager* analysisManager = G4AnalysisManager::Instance();
  analysisManager -> OpenFile("data_La_double");

  analysisManager -> CreateNtuple("data", "data");
  analysisManager -> SetFirstNtupleId(0);
  analysisManager -> CreateNtupleIColumn("eventID");
  analysisManager -> CreateNtupleIColumn("volumeID");
  analysisManager -> CreateNtupleIColumn("particleID");
  analysisManager -> CreateNtupleDColumn("edep");
  analysisManager -> CreateNtupleDColumn("KineticEnergy");
  analysisManager -> FinishNtuple();


}

void RunAction::EndOfRunAction(const G4Run*)
{
  G4AnalysisManager* analysisManager = G4AnalysisManager::Instance();
  analysisManager -> Write();
  analysisManager -> CloseFile();
}
