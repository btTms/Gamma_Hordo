#ifndef YOURMOUNTING_HH
#define YOURMOUNTING_HH

#include <G4LogicalVolume.hh>
#include <G4RotationMatrix.hh>
#include <G4Tubs.hh>
#include <G4Material.hh>
#include <G4PVPlacement.hh>
#include <G4VisAttributes.hh>
#include <G4SystemOfUnits.hh>

class YourMounting{

    public:
        YourMounting();
        ~YourMounting();

        void Build(G4LogicalVolume* motherLogicalVolume, G4Material* buildMaterial);

    private:

        void InitialiseAttributes();

        G4double pRmin, pRmax, pDz;
        G4Tubs* mountingVolume;
        G4LogicalVolume* mountingLogicalVolume;
        G4VPhysicalVolume* mountingPhysicalVolume;
        G4RotationMatrix* rotationMatrix;

};

#endif 