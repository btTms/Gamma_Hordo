#ifndef YOURDETECTORCONSTRUCTION_HH
#define YOURDETECTORCONSTRUCTION_HH

#include <G4ThreeVector.hh>
#include <vector>
#include <fstream>

// G4 prerequisites
#include "G4VUserDetectorConstruction.hh"
#include <G4Material.hh>
#include <G4NistManager.hh>
#include <G4VPhysicalVolume.hh>
#include "G4Box.hh"
#include "G4Types.hh"
#include "G4LogicalVolume.hh"
#include "G4VPhysicalVolume.hh"
#include "G4VUserDetectorConstruction.hh"
#include "G4Material.hh"
#include <G4PVPlacement.hh>
#include <G4ios.hh>
#include "G4SDManager.hh"
#include <G4SystemOfUnits.hh>
#include "YourBarrelVerticalWall.hh"
#include "YourSensitiveDetector.hh"

#include "YourShieldingSideWall.hh"
#include "YourWorldBox.hh"
#include "Materials.hh"
#include "YourGround.hh"
#include "YourMounting.hh"
#include "YourExternalBackgroundSource.hh"
#include "YourBarrel.hh"
#include "YourShielding.hh"
#include "YourDetector.hh"


class YourDetectorConstruction : public G4VUserDetectorConstruction {
    public:
        YourDetectorConstruction();
        virtual ~YourDetectorConstruction();

        virtual G4VPhysicalVolume* Construct();

    private:

        virtual void ConstructSDandField();
        void SetDetectorPositionsAndAngles();
        void BuildDetectors();

        Materials* materialsTable;

        YourWorldBox* worldBox;
        YourGround* ground;
        YourMounting* mounting;
        YourExternalBackgroundSource* externalBackgroundSource;
        YourBarrel* barrel;
        YourShielding* shielding;

        std::vector<YourDetector*> detectors;
        std::vector<G4ThreeVector> detectorTranslations;
        std::vector<G4double> detectorAngles;
        

};

#endif