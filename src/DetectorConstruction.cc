#include "DetectorConstruction.hh"

#include "G4RunManager.hh"
#include "G4NistManager.hh"
#include "G4Box.hh"
#include "G4Tubs.hh"
#include "G4LogicalVolume.hh"
#include "G4PVPlacement.hh"
#include "G4SystemOfUnits.hh"
#include "G4Element.hh"
#include "G4Material.hh"
#include "G4VSolid.hh"
#include "G4RotationMatrix.hh"
#include "G4SubtractionSolid.hh"
#include "G4AssemblyVolume.hh"
#include "stdio.h"
#include <iostream>

DetectorConstruction::DetectorConstruction()
: G4VUserDetectorConstruction()
{
}

DetectorConstruction::~DetectorConstruction()
{
}

G4VPhysicalVolume* DetectorConstruction::Construct()
{  
	G4NistManager* nist = G4NistManager::Instance();


G4Material* world_mat = nist -> FindOrBuildMaterial("G4_AIR");
  G4double world_size = 5000*mm;

  G4Box* solidWorld =
    new G4Box("World",                       // its name
              0.5*world_size,                // half x
              0.5*world_size,                // half y
              0.5*world_size);               // half z

  G4LogicalVolume* logicWorld =
    new G4LogicalVolume(solidWorld,          //its solid
                        world_mat,           //its material
                        "World");            //its name

  G4VPhysicalVolume* physWorld =
    new G4PVPlacement(0,                     //no rotation
                      G4ThreeVector(),       //at (0,0,0)
                      logicWorld,            //its logical volume
                      "World",               //its name
                      0,                     //its mother  volume
                      false,                 //no boolean operation
                      0,                     //copy number
                      true);                 //overlaps checking

  G4Material* detector_mat = nist -> FindOrBuildMaterial("G4_Al");




 G4Element* element_La = new G4Element("lanthanum", "La",57., 138.90547*g/mole);
  G4Element* element_Br = new G4Element("bromine", "Br",35., 79.904*g/mole);
  G4Element* element_Ce = new G4Element("cerium", "Ce",58., 140.116*g/mole);
  G4Material* laBr3 = new G4Material("lanthanumbromide",5.06*g/cm3,2,kStateSolid,300*kelvin);
  G4Material* scin_mat = new G4Material("scintill",5.2*g/cm3,2,kStateSolid,300*kelvin);
  laBr3 -> AddElement(element_La,1);
  laBr3 -> AddElement(element_Br,3);
  scin_mat -> AddMaterial(laBr3,99.5*perCent);
  scin_mat -> AddElement(element_Ce, 0.5*perCent);


  G4double atomicNumber = 1.;
  G4double massOfMole = 1.008*g/mole;
  G4double density = 1.e-25*g/cm3;
  G4double temperature = 2.73*kelvin;
  G4double pressure = 3.e-18*pascal;
  G4Material* Vacuum = new G4Material("interGalactic",
                  atomicNumber, massOfMole, density,
                  kStateGas,temperature, pressure);

/*

  G4Tubs* solidDetector =
    new G4Tubs("Detector",43.5/2*mm,44.5/2*mm,(148.5-38.7)/2*mm,0.*deg,360.*deg);
  G4Tubs* solidDetector1 =
    new G4Tubs("Detector1",42.1/2*mm,43.1/2*mm,38.7/2*mm,0.*deg,360.*deg);
  G4Tubs* solidDetector3 =
    new G4Tubs("Detector3",0*mm,42.1/2*mm,0.5/2*mm,0*deg,360.*deg);
  G4Tubs* solidDetector2 =
    new G4Tubs("Detector2",0*mm,38.1/2*mm,38.1/2*mm,0.*deg,360.*deg);
  G4Tubs* solidDetector4 =
    new G4Tubs("Detector4",0*mm,38.1/2*mm,1./2*mm,0.*deg,360.*deg);
  G4Tubs* solidDetector5 =
    new G4Tubs("Detector5",38.1/2*mm,42.1/2*mm,38.2/2*mm,0.*deg,360.*deg);
  G4Tubs* solidDetector6 =
    new G4Tubs("Detector6",43.1/2*mm,43.5/2*mm,0.5/2*mm,0.*deg,360.*deg);
  G4Tubs* solidDetector7 =
    new G4Tubs("Detector7",38.1/2*mm,43.5/2*mm,0.9/2*mm,0.*deg,360.*deg);
  G4Tubs* solidDetector8 =
    new G4Tubs("Detector8",0*mm,43.5/2*mm,(148.5-38.7-0.4)/2*mm,0.*deg,360.*deg);
//  G4Box* Al_out =
//    new G4Box("Al_out",43.1/2,5/2,(148.5*2+40)/2);
//  G4Box* Al_out2 =
//    new G4Box("Al_out2",43.1/2,5/2,(148.5*2+40)/2);

 G4LogicalVolume* logicDetector =
    new G4LogicalVolume(solidDetector,detector_mat,"Detector");
    new G4PVPlacement(0,G4ThreeVector(0,0,-113.6),logicDetector,"Detector1",logicWorld,false,1,true);

 G4LogicalVolume* logicDetector1 =
    new G4LogicalVolume(solidDetector1,detector_mat,"Detector1");
    new G4PVPlacement(0,G4ThreeVector(0,0,(74.25-113.6)),logicDetector1,"Detector1",logicWorld,false,1,true);

 G4LogicalVolume* logicDetector2 =
    new G4LogicalVolume(solidDetector2,scin_mat,"Detector2");
    new G4PVPlacement(0,G4ThreeVector(0,0,(73.05-113.6)),logicDetector2,"Detector2",logicWorld,false,100,true);

 G4LogicalVolume* logicDetector3 =
    new G4LogicalVolume(solidDetector3,detector_mat,"Detector3");
    new G4PVPlacement(0,G4ThreeVector(0,0,(93.6-0.25-113.6)),logicDetector3,"Detector3",logicWorld,false,1,true);

 G4LogicalVolume* logicDetector4 =
    new G4LogicalVolume(solidDetector4,Vacuum,"Detector4");
    new G4PVPlacement(0,G4ThreeVector(0,0,(92.6-113.6)),logicDetector4,"Detector4",logicWorld,false,1,true);
 G4LogicalVolume* logicDetector5 =
   new G4LogicalVolume(solidDetector5,Vacuum,"Detector5");
    new G4PVPlacement(0,G4ThreeVector(0,0,(54.9+19.1-113.6)),logicDetector5,"Detector5",logicWorld,false,1,true);
 G4LogicalVolume* logicDetector6 =
    new G4LogicalVolume(solidDetector6,detector_mat,"Detector6");
    new G4PVPlacement(0,G4ThreeVector(0,0,(54.9-0.25-113.6)),logicDetector6,"Detector6",logicWorld,false,1,true);
 G4LogicalVolume* logicDetector7 =
    new G4LogicalVolume(solidDetector7,Vacuum,"Detector7");
    new G4PVPlacement(0,G4ThreeVector(0,0,(54.9-0.9+0.2-113.6)),logicDetector7,"Detector7",logicWorld,false,1,true);
 G4LogicalVolume* logicDetector8 =
    new G4LogicalVolume(solidDetector8,Vacuum,"Detector8");
    new G4PVPlacement(0,G4ThreeVector(0,0,(-0.45-113.6)),logicDetector8,"Detector8",logicWorld,false,1,true);

 //G4LogicalVolume* logicAl_out =
 //   new G4LogicalVolume(Al_out,detector_mat,"logicAl_out");
 //   new G4PVPlacement(0,G4ThreeVector(0,43.1/2+2.5,0),logicAl_out,"Al_out",logicWorld,false,333,true);
 //G4LogicalVolume* logicAl_out2 =
 //   new G4LogicalVolume(Al_out2,detector_mat,"logicAl_out2");
 //   new G4PVPlacement(0,G4ThreeVector(0,-43.1/2-2.5,0),logicAl_out2,"Al_out2",logicWorld,false,333,true);






  G4Tubs* FsolidDetector =
    new G4Tubs("FDetector",43.5/2*mm,44.5/2*mm,(148.5-38.7)/2*mm,0.*deg,360.*deg);
  G4Tubs* FsolidDetector1 =
    new G4Tubs("FDetector1",42.1/2*mm,43.1/2*mm,38.7/2*mm,0.*deg,360.*deg);
  G4Tubs* FsolidDetector3 =
    new G4Tubs("FDetector3",0*mm,42.1/2*mm,0.5/2*mm,0*deg,360.*deg);
  G4Tubs* FsolidDetector2 =
  new G4Tubs("FDetector2",0*mm,38.1/2*mm,38.1/2*mm,0.*deg,360.*deg);
  G4Tubs* FsolidDetector4 =
    new G4Tubs("FDetector4",0*mm,38.1/2*mm,1./2*mm,0.*deg,360.*deg);
  G4Tubs* FsolidDetector5 =
    new G4Tubs("FDetector5",38.1/2*mm,42.1/2*mm,38.2/2*mm,0.*deg,360.*deg);
  G4Tubs* FsolidDetector6 =
    new G4Tubs("FDetector6",43.1/2*mm,43.5/2*mm,0.5/2*mm,0.*deg,360.*deg);
  G4Tubs* FsolidDetector7 =
    new G4Tubs("FDetector7",38.1/2*mm,43.5/2*mm,0.9/2*mm,0.*deg,360.*deg);
  G4Tubs* FsolidDetector8 =
    new G4Tubs("FDetector8",0*mm,43.5/2*mm,(148.5-38.7-0.4)/2*mm,0.*deg,360.*deg);

 G4LogicalVolume* FlogicDetector =
    new G4LogicalVolume(FsolidDetector,detector_mat,"FDetector");
    new G4PVPlacement(0,G4ThreeVector(0,0,113.6),FlogicDetector,"FDetector1",logicWorld,false,1,true);

 G4LogicalVolume* FlogicDetector1 =
    new G4LogicalVolume(FsolidDetector1,detector_mat,"FDetector1");
    new G4PVPlacement(0,G4ThreeVector(0,0,-(74.25-113.6)),FlogicDetector1,"FDetector1",logicWorld,false,1,true);

 G4LogicalVolume* FlogicDetector2 =
    new G4LogicalVolume(FsolidDetector2,scin_mat,"FDetector2");
    new G4PVPlacement(0,G4ThreeVector(0,0,-(73.05-113.6)),FlogicDetector2,"FDetector2",logicWorld,false,200,true);

 G4LogicalVolume* FlogicDetector3 =
    new G4LogicalVolume(FsolidDetector3,detector_mat,"FDetector3");
    new G4PVPlacement(0,G4ThreeVector(0,0,-(93.6-0.25-113.6)),FlogicDetector3,"FDetector3",logicWorld,false,1,true);

 G4LogicalVolume* FlogicDetector4 =
    new G4LogicalVolume(FsolidDetector4,Vacuum,"FDetector4");
    new G4PVPlacement(0,G4ThreeVector(0,0,-(92.6-113.6)),FlogicDetector4,"FDetector4",logicWorld,false,1,true);
 G4LogicalVolume* FlogicDetector5 =
    new G4LogicalVolume(FsolidDetector5,Vacuum,"FDetector5");
    new G4PVPlacement(0,G4ThreeVector(0,0,-(54.9+19.1-113.6)),FlogicDetector5,"FDetector5",logicWorld,false,1,true);
 G4LogicalVolume* FlogicDetector6 =
    new G4LogicalVolume(FsolidDetector6,detector_mat,"FDetector6");
    new G4PVPlacement(0,G4ThreeVector(0,0,-(54.9-0.25-113.6)),FlogicDetector6,"FDetector6",logicWorld,false,1,true);
 G4LogicalVolume* FlogicDetector7 =
    new G4LogicalVolume(FsolidDetector7,Vacuum,"FDetector7");
    new G4PVPlacement(0,G4ThreeVector(0,0,-(54.9-0.9+0.2-113.6)),FlogicDetector7,"FDetector7",logicWorld,false,1,true);
 G4LogicalVolume* FlogicDetector8 =
    new G4LogicalVolume(FsolidDetector8,Vacuum,"FDetector8");
    new G4PVPlacement(0,G4ThreeVector(0,0,-(-0.45-113.6)),FlogicDetector8,"FDetector8",logicWorld,false,1,true);



*/


/*
double a;

for(int i=0;i<8;i++)
{
for(int j=-1;j<2;j++)

{
  G4Tubs* FsolidDetector =
    new G4Tubs("FDetector",43.5/2*mm,44.5/2*mm,(148.5-38.7)/2*mm,0.*deg,360.*deg);
  G4Tubs* FsolidDetector1 =
    new G4Tubs("FDetector1",42.1/2*mm,43.1/2*mm,38.7/2*mm,0.*deg,360.*deg);
  G4Tubs* FsolidDetector3 =
    new G4Tubs("FDetector3",0*mm,42.1/2*mm,0.5/2*mm,0*deg,360.*deg);
  G4Tubs* FsolidDetector2 =
  new G4Tubs("FDetector2",0*mm,38.1/2*mm,38.1/2*mm,0.*deg,360.*deg);
  G4Tubs* FsolidDetector4 =
    new G4Tubs("FDetector4",0*mm,38.1/2*mm,1./2*mm,0.*deg,360.*deg);
  G4Tubs* FsolidDetector5 =
    new G4Tubs("FDetector5",38.1/2*mm,42.1/2*mm,38.2/2*mm,0.*deg,360.*deg);
  G4Tubs* FsolidDetector6 =
    new G4Tubs("FDetector6",43.1/2*mm,43.5/2*mm,0.5/2*mm,0.*deg,360.*deg);
  G4Tubs* FsolidDetector7 =
    new G4Tubs("FDetector7",38.1/2*mm,43.5/2*mm,0.9/2*mm,0.*deg,360.*deg);
  G4Tubs* FsolidDetector8 =
    new G4Tubs("FDetector8",0*mm,43.5/2*mm,(148.5-38.7-0.4)/2*mm,0.*deg,360.*deg);
 G4RotationMatrix* boxRotation = new G4RotationMatrix;
 boxRotation->rotateX(45*deg*i);
 boxRotation->rotateY(25*deg*j);

a=((113.6+70));
 G4LogicalVolume* FlogicDetector =
    new G4LogicalVolume(FsolidDetector,detector_mat,"FDetector");
    new G4PVPlacement(boxRotation,G4ThreeVector(-sin(25*j*deg)*a*1,(113.6+70)*sin(45*i*deg)*cos(24*j*deg),(113.6+70)*cos(45*i*deg)*cos(25*deg*j)),FlogicDetector,"FDetector",logicWorld,false,1,true);

a=-((74.25-(113.6+70)));
 G4LogicalVolume* FlogicDetector1 =
    new G4LogicalVolume(FsolidDetector1,detector_mat,"FDetector1");
    new G4PVPlacement(boxRotation,G4ThreeVector(-sin(25*j*deg)*a*1,-(74.25-(113.6+70))*sin(45*i*deg)*cos(24*j*deg),-(74.25-(113.6+70))*cos(45*i*deg)*cos(25*deg*j)),FlogicDetector1,"FDetector1",logicWorld,false,1,true);

a=-(((73.05-(113.6+70))));
 G4LogicalVolume* FlogicDetector2 =
    new G4LogicalVolume(FsolidDetector2,scin_mat,"FDetector2");
    new G4PVPlacement(boxRotation,G4ThreeVector(-sin(25*j*deg)*a*1,-(73.05-(113.6+70))*sin(45*i*deg)*cos(24*j*deg),-(73.05-(113.6+70))*cos(45*i*deg)*cos(25*deg*j)),FlogicDetector2,"FDetector2",logicWorld,false,200,true);

a=-(((93.6-0.25-(113.6+70))));
 G4LogicalVolume* FlogicDetector3 =
    new G4LogicalVolume(FsolidDetector3,detector_mat,"FDetector3");
    new G4PVPlacement(boxRotation,G4ThreeVector(-sin(25*j*deg)*a*1,-(93.6-0.25-(113.6+70))*sin(45*i*deg)*cos(24*j*deg),-(93.6-0.25-(113.6+70))*cos(45*i*deg)*cos(25*deg*j)),FlogicDetector3,"FDetector3",logicWorld,false,1,true);

a=-(((92.6-(113.6+70))));
 G4LogicalVolume* FlogicDetector4 =
    new G4LogicalVolume(FsolidDetector4,Vacuum,"FDetector4");
    new G4PVPlacement(boxRotation,G4ThreeVector(-sin(25*j*deg)*a*1,-(92.6-(113.6+70))*sin(45*i*deg)*cos(24*j*deg),-(92.6-(113.6+70))*cos(45*i*deg)*cos(25*deg*j)),FlogicDetector4,"FDetector4",logicWorld,false,1,true);
a=-(((54.9+19.1-(113.6+70))));
 G4LogicalVolume* FlogicDetector5 =
    new G4LogicalVolume(FsolidDetector5,Vacuum,"FDetector5");
    new G4PVPlacement(boxRotation,G4ThreeVector(-sin(25*j*deg)*a*1,-(54.9+19.1-(113.6+70))*sin(45*i*deg)*cos(24*j*deg),-(54.9+19.1-(113.6+70))*cos(45*i*deg)*cos(25*deg*j)),FlogicDetector5,"FDetector5",logicWorld,false,1,true);
a=-(((54.9-0.25-(113.6+70))));
 G4LogicalVolume* FlogicDetector6 =
    new G4LogicalVolume(FsolidDetector6,detector_mat,"FDetector6");
    new G4PVPlacement(boxRotation,G4ThreeVector(-sin(25*j*deg)*a*1,-(54.9-0.25-(113.6+70))*sin(45*i*deg)*cos(24*j*deg),-(54.9-0.25-(113.6+70))*cos(45*i*deg)*cos(25*deg*j)),FlogicDetector6,"FDetector6",logicWorld,false,1,true);
a=-(((54.9-0.9+0.2-(113.6+70))));
 G4LogicalVolume* FlogicDetector7 =
    new G4LogicalVolume(FsolidDetector7,Vacuum,"FDetector7");
    new G4PVPlacement(boxRotation,G4ThreeVector(-sin(25*j*deg)*a*1,-(54.9-0.9+0.2-(113.6+70))*sin(45*i*deg)*cos(24*j*deg),-(54.9-0.9+0.2-(113.6+70))*cos(45*i*deg)*cos(25*deg*j)),FlogicDetector7,"FDetector7",logicWorld,false,1,true);
a=-(((-0.45-(113.6+70))));
 G4LogicalVolume* FlogicDetector8 =
    new G4LogicalVolume(FsolidDetector8,Vacuum,"FDetector8");
    new G4PVPlacement(boxRotation,G4ThreeVector(-sin(25*j*deg)*a*1,-(-0.45-(113.6+70))*sin(45*i*deg)*cos(24*j*deg),-(-0.45-(113.6+70))*cos(45*i*deg)*cos(25*deg*j)),FlogicDetector8,"FDetector8",logicWorld,false,1,true);




}
}

*/

//-----------------------------double ------------------------------
G4Tubs* Detector1 =
    new G4Tubs("Detector1",0*mm,43.1/2*mm,38.7/2*mm,0.*deg,360.*deg);
G4Tubs* Detector2 =
  new G4Tubs("Detector2",0*mm,38.1/2*mm,(38.7-1)/2*mm,0.*deg,360.*deg);

G4Tubs* scin =
    new G4Tubs("scin",0*mm,38.1/2*mm,38.1/2*mm,0.*deg,360.*deg);
G4SubtractionSolid* Detector_scin = 
    new G4SubtractionSolid("Detector_scin",Detector1,Detector2);
G4Tubs* Detector_pmt =
    new G4Tubs("Detectr_pmt",0*mm,44.5/2*mm,(148.5-38.7)/2*mm,0.*deg,360.*deg);

double a;
double distance=25;

		a=(distance+38.7/2+0.2);
		G4LogicalVolume* logic_scin =
			new G4LogicalVolume(scin,scin_mat,"scin");
			new G4PVPlacement(0,G4ThreeVector(0,0,a),logic_scin,"scin",logicWorld,false,200,true);
		a=(distance+38.7/2);
		G4LogicalVolume* logicDetector_scin =
			new G4LogicalVolume(Detector_scin,detector_mat,"Detector_scin");
			new G4PVPlacement(0,G4ThreeVector(0,0,a),logicDetector_scin,"Detector_scin",logicWorld,false,1,true);
		a=(distance+(148.5-38.7)/2+38.7);
		G4LogicalVolume* logicDetector_pmt =
			new G4LogicalVolume(Detector_pmt,detector_mat,"Detector_pmt");
			new G4PVPlacement(0,G4ThreeVector(0,0,a),logicDetector_pmt,"Detector_pmt",logicWorld,false,1,true);

		a=-(distance+38.7/2+0.2);
		G4LogicalVolume* logic_scin1 =
			new G4LogicalVolume(scin,scin_mat,"scin");
			new G4PVPlacement(0,G4ThreeVector(0,0,a),logic_scin,"scin",logicWorld,false,400,true);
		a=-(distance+38.7/2);
		G4LogicalVolume* logicDetector_scin1 =
			new G4LogicalVolume(Detector_scin,detector_mat,"Detector_scin");
			new G4PVPlacement(0,G4ThreeVector(0,0,a),logicDetector_scin,"Detector_scin",logicWorld,false,1,true);
		a=-(distance+(148.5-38.7)/2+38.7);
		G4LogicalVolume* logicDetector_pmt1 =
			new G4LogicalVolume(Detector_pmt,detector_mat,"Detector_pmt");
			new G4PVPlacement(0,G4ThreeVector(0,0,a),logicDetector_pmt,"Detector_pmt",logicWorld,false,1,true);
//-----------------------double ----




//  -----------ring type-------------

/*
G4Tubs* Detector1 =
    new G4Tubs("Detector1",0*mm,43.1/2*mm,38.7/2*mm,0.*deg,360.*deg);
G4Tubs* Detector2 =
  new G4Tubs("Detector2",0*mm,38.1/2*mm,(38.7-1)/2*mm,0.*deg,360.*deg);

G4Tubs* scin =
    new G4Tubs("scin",0*mm,38.1/2*mm,38.1/2*mm,0.*deg,360.*deg);
G4SubtractionSolid* Detector_scin = 
    new G4SubtractionSolid("Detector_scin",Detector1,Detector2);
G4Tubs* Detector_pmt =
    new G4Tubs("Detectr_pmt",0*mm,44.5/2*mm,(148.5-38.7)/2*mm,0.*deg,360.*deg);

double a;
double distance=110;
for(int i=0;i<8;i++)
{
	for(int j=-1;j<2;j++)

	{
		G4RotationMatrix* boxRotation = new G4RotationMatrix;
		boxRotation->rotateX(45*deg*i);
		boxRotation->rotateY(25*deg*j);

		a=(distance+38.7/2+0.2);
		G4LogicalVolume* logic_scin =
			new G4LogicalVolume(scin,scin_mat,"scin");
			new G4PVPlacement(boxRotation,G4ThreeVector(-sin(25*j*deg)*a,a*sin(45*i*deg)*cos(24*j*deg),a*cos(45*i*deg)*cos(25*deg*j)),logic_scin,"scin",logicWorld,false,(200+(j+2)*10+(i+1)),true);
		a=(distance+38.7/2);
		G4LogicalVolume* logicDetector_scin =
			new G4LogicalVolume(Detector_scin,detector_mat,"Detector_scin");
			new G4PVPlacement(boxRotation,G4ThreeVector(-sin(25*j*deg)*a,a*sin(45*i*deg)*cos(24*j*deg),a*cos(45*i*deg)*cos(25*deg*j)),logicDetector_scin,"Detector_scin",logicWorld,false,1,true);
		a=(distance+(148.5-38.7)/2+38.7);
		G4LogicalVolume* logicDetector_pmt =
			new G4LogicalVolume(Detector_pmt,detector_mat,"Detector_pmt");
			new G4PVPlacement(boxRotation,G4ThreeVector(-sin(25*j*deg)*a,a*sin(45*i*deg)*cos(24*j*deg),a*cos(45*i*deg)*cos(25*deg*j)),logicDetector_pmt,"Detector_pmt",logicWorld,false,1,true);
	}
}
*/

//---------------------------------------//






/*
//---------------------4cluster------------------------

G4Tubs* Detector1 =
new G4Tubs("Detector1",0*mm,43.1/2*mm,38.7/2*mm,0.*deg,360.*deg);
G4Tubs* Detector2 =
new G4Tubs("Detector2",0*mm,38.1/2*mm,(38.7-1)/2*mm,0.*deg,360.*deg);

G4Tubs* scin =
new G4Tubs("scin",0*mm,38.1/2*mm,38.1/2*mm,0.*deg,360.*deg);
G4SubtractionSolid* Detector_scin =
new G4SubtractionSolid("Detector_scin",Detector1,Detector2);
G4Tubs* Detector_pmt =
new G4Tubs("Detectr_pmt",0*mm,44.5/2*mm,(148.5-38.7)/2*mm,0.*deg,360.*deg);

double a;
int j=0;
int i=0;
G4RotationMatrix* boxRotation = new G4RotationMatrix;
boxRotation->rotateX(45*deg*i);
boxRotation->rotateY(25*deg*j);

for(i=0;i<4;i++){


double num;
if(i%2==0)
{
	num=i-1;
}
else
{
	num=i-2;
}

a=(50+38.7/2+0.2);
G4LogicalVolume* logic_scin =
new G4LogicalVolume(scin,scin_mat,"scin");
new G4PVPlacement(0,G4ThreeVector((-44.5/2*(i-num-2)*num),44.5*sqrt(3)*(i-num-1)/2*(-num),a),logic_scin,"scin",logicWorld,false,200*(i+1),true);

a=(50+38.7/2);
G4LogicalVolume* logicDetector_scin =
new G4LogicalVolume(Detector_scin,detector_mat,"Detector_scin");
new G4PVPlacement(0,G4ThreeVector((-44.5/2*(i-num-2)*num),44.5*sqrt(3)*(i-num-1)/2*(-num),a),logicDetector_scin,"Detector_scin",logicWorld,false,1,true);

a=(50+(148.5-38.7)/2+38.7);

G4LogicalVolume* logicDetector_pmt =
new G4LogicalVolume(Detector_pmt,detector_mat,"Detector_pmt");
new G4PVPlacement(0,G4ThreeVector((-44.5/2*(i-num-2)*num),44.5*sqrt(3)*(i-num-1)/2*(-num),a),logicDetector_pmt,"Detector_pmt",logicWorld,false,1,true);


}
//------------------------------------------
*/


//----------6 detector---------------
/*
 
G4Tubs* Detector1 =
new G4Tubs("Detector1",0*mm,43.1/2*mm,38.7/2*mm,0.*deg,360.*deg);
G4Tubs* Detector2 =
new G4Tubs("Detector2",0*mm,38.1/2*mm,(38.7-1)/2*mm,0.*deg,360.*deg);

G4Tubs* scin =
new G4Tubs("scin",0*mm,38.1/2*mm,38.1/2*mm,0.*deg,360.*deg);
G4SubtractionSolid* Detector_scin = 
new G4SubtractionSolid("Detector_scin",Detector1,Detector2);
G4Tubs* Detector_pmt =
new G4Tubs("Detectr_pmt",0*mm,44.5/2*mm,(148.5-38.7)/2*mm,0.*deg,360.*deg);

double a;

for(int k=0;k<2;k++)
{
//for(int i=0;i<3;i++)
int i=0;
{
	for(int j=-1;j<2;j++)
	{
		G4RotationMatrix* boxRotation = new G4RotationMatrix;
		boxRotation->rotateZ(120*deg*i*(1-2*k));
		boxRotation->rotateY(-25*deg*j*(1-2*k));
		boxRotation->rotateX(-25*deg*(abs(j)*2-1));

		a=(70+38.7/2+0.2);
		G4LogicalVolume* logic_scin =
		new G4LogicalVolume(scin,scin_mat,"scin");
		new G4PVPlacement(boxRotation,G4ThreeVector(sin(25*deg*j)*cos(25*deg)*a,sin(-25*deg*(abs(j)*2-1))*a*(1-2*k),a*(cos(-25*deg*(abs(j)*2-1)))*cos(25*deg*j)*(1-2*k)),logic_scin,"scin",logicWorld,false,200,true);
		
		a=(70+38.7/2);
		G4LogicalVolume* logicDetector_scin =
		new G4LogicalVolume(Detector_scin,detector_mat,"Detector_scin");
		new G4PVPlacement(boxRotation,G4ThreeVector(sin(25*j*deg)*cos(25*deg)*a,sin(-25*deg*(abs(j)*2-1))*a*(1-2*k),a*cos(-25*deg*(abs(j)*2-1))*cos(25*deg*j)*(1-2*k)),logicDetector_scin,"Detector_scin",logicWorld,false,1,true);
		
		a=(70+(148.5-38.7)/2+38.7);
		G4LogicalVolume* logicDetector_pmt =
		new G4LogicalVolume(Detector_pmt,detector_mat,"Detector_pmt");
		new G4PVPlacement(boxRotation,G4ThreeVector(sin(25*deg*j)*cos(25*deg)*a,sin(-25*deg*(abs(j)*2-1))*a*(1-2*k),a*cos(-25*deg*(abs(j)*2-1))*cos(25*deg*j)*(1-2*k)),logicDetector_pmt,"Detector_pmt",logicWorld,false,1,true);
	}
}

}
*/
//---------------------------------



 //-------------------------6 x cluster -----------------------------------------------------
 /*
G4Tubs* Detector1 =
new G4Tubs("Detector1",0*mm,43.1/2*mm,38.7/2*mm,0.*deg,360.*deg);
G4Tubs* Detector2 =
new G4Tubs("Detector2",0*mm,38.1/2*mm,(38.7-1)/2*mm,0.*deg,360.*deg);

G4Tubs* scin =
new G4Tubs("scin",0*mm,38.1/2*mm,38.1/2*mm,0.*deg,360.*deg);
G4SubtractionSolid* Detector_scin =
new G4SubtractionSolid("Detector_scin",Detector1,Detector2);
G4Tubs* Detector_pmt =
new G4Tubs("Detectr_pmt",0*mm,44.5/2*mm,(148.5-38.7)/2*mm,0.*deg,360.*deg);

double a;
int k=0;
int j;
double angle=55;
double distance=110;

for(k=0;k<2;k++)
{

for(j=-1;j<2;j++)
{
 
G4ThreeVector *Rotaxis=new G4ThreeVector(-sin(30*deg)*(abs(j)*2-1),cos(30*deg)*j,0);
  G4RotationMatrix* boxRotation = new G4RotationMatrix;
  boxRotation->rotate(-angle*deg,Rotaxis);
  //G4RotationMatrix* boxRotation2 = new G4RotationMatrix;
  //boxRotation2->rotate(-30*deg,Rotaxis);
  //boxRotation2->rotateZ(-60*deg);
  //G4RotationMatrix* boxRotation3 = new G4RotationMatrix;
  //boxRotation3->rotate(-30*deg,Rotaxis);
  //boxRotation3->rotateZ(60*deg);



for(int i=0;i<4;i++){


double num;
if(i%2==0)
{
        num=i-1;
}
else
{
        num=i-2;
}

a=(distance+38.7/2+0.2);
G4LogicalVolume* logic_scin =
new G4LogicalVolume(scin,scin_mat,"scin");
new G4PVPlacement(boxRotation,G4ThreeVector((-44.5/2*(i-num-2)*num)*(1-2*k),44.5*sqrt(3)*(i-num-1)/2*(-num)*(1-2*k),a*(1-2*k)).rotate(angle*deg,G4ThreeVector(-sin(30*deg)*(abs(j)*2-1),cos(30*deg)*j,0)),logic_scin,"scin",logicWorld,false,10*(i+1)*(j+6)*(2*k-1),true);

a=(distance+38.7/2);
G4LogicalVolume* logicDetector_scin =
new G4LogicalVolume(Detector_scin,detector_mat,"Detector_scin");
new G4PVPlacement(boxRotation,G4ThreeVector((-44.5/2*(i-num-2)*num)*(1-2*k),44.5*sqrt(3)*(i-num-1)/2*(-num)*(1-2*k),a*(1-2*k)).rotate(angle*deg,G4ThreeVector(-sin(30*deg)*(abs(j)*2-1),cos(30*deg)*j,0)),logicDetector_scin,"Detector_scin",logicWorld,false,1,true);

a=(distance+(148.5-38.7)/2+38.7);

G4LogicalVolume* logicDetector_pmt =
new G4LogicalVolume(Detector_pmt,detector_mat,"Detector_pmt");
new G4PVPlacement(boxRotation,G4ThreeVector((-44.5/2*(i-num-2)*num)*(1-2*k),44.5*sqrt(3)*(i-num-1)/2*(-num)*(1-2*k),a*(1-2*k)).rotate(angle*deg,G4ThreeVector(-sin(30*deg)*(abs(j)*2-1),cos(30*deg)*j,0)),logicDetector_pmt,"Detector_pmt",logicWorld,false,1,true);



}


}
}
*/
//-------------------------------------------------------------------





G4Element* C = new G4Element("Carbon", "C", 6., 12.011*g/mole);
G4Element* H = new G4Element("Hydrogen", "H", 1., 1.00794*g/mole);

G4Material* plastic_mat = new G4Material("Plastic",  1.032*g/cm3, 2);
        plastic_mat->AddElement(C, 9);
        plastic_mat->AddElement(H, 10);

//-----------------source capsule----
G4VSolid* source_encap = new G4Tubs("source_encap", 0.*mm, 0.5*25.5*mm, 0.5*6.3*mm, 0., 2*M_PI*rad);
        G4LogicalVolume* log_source_encap = new G4LogicalVolume(source_encap, plastic_mat, "SourceCase");




new G4PVPlacement(0, G4ThreeVector(0.*mm,0.*mm, 0.*mm),log_source_encap, "SourceCase", logicWorld, false, 1);

//----------------source capsule-----*/

//----------beam line
/*
 G4Box* chamber =
   new G4Box("chamber",                       // its name
             50,                // half x
             35,                // half y
             800);               // half z
 G4LogicalVolume* log_cham =
   new G4LogicalVolume(chamber,          //its solid
                       plastic_mat,           //its material
                       "chamber");            //its name
   new G4PVPlacement(0,                     //no rotation
                     G4ThreeVector(),       //at (0,0,0)
                     log_cham,            //its logical volume
                     "chamber",               //its name
                     logicWorld,                     //its mother  volume
                     false,                 //no boolean operation
                     0,                     //copy number
                     true);                 //overlaps checking
*/





















return physWorld;
}
