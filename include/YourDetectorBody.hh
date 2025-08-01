#ifndef YOURDETECTORBODY_HH
#define YOURDETECTORBODY_HH

#include <G4LogicalVolume.hh>
#include <G4RotationMatrix.hh>
#include <G4ThreeVector.hh>
#include <G4Tubs.hh>
#include <G4Material.hh>
#include <G4PVPlacement.hh>
#include <G4Types.hh>
#include <G4VisAttributes.hh>
#include <G4SystemOfUnits.hh>

class YourDetectorBody {
    public:
        YourDetectorBody();
        ~YourDetectorBody();

        void Build(G4LogicalVolume* motherVolume, G4Material* material, G4ThreeVector translate);

    private:
        void InitialiseAttributes();

        G4double pRmin, pRmax, pDz;
        G4Tubs* detectorBodyVolume;
        G4LogicalVolume* detectorBodyLogicalVolume;
        G4VPhysicalVolume* detectorBodyPhysicalVolume;
};


#endif