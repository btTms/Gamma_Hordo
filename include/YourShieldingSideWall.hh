#ifndef YOURSHIELDINGSIDEWALL_HH
#define YOURSHIELDINGSIDEWALL_HH

#include <G4LogicalVolume.hh>
#include <G4RotationMatrix.hh>
#include <G4Tubs.hh>
#include <G4Material.hh>
#include <G4PVPlacement.hh>
#include <G4VisAttributes.hh>
#include <G4SystemOfUnits.hh>

class YourShieldingSideWall{

    public:
        YourShieldingSideWall();
        ~YourShieldingSideWall();

        void Build(G4LogicalVolume* motherLogicalVolume, G4Material* buildMaterial);

    private:
        void InitialiseAttributes();

        G4double pRmin, pRmax, pDz;
        G4Tubs* barrelSideWallVolume;
        G4LogicalVolume* shieldingSideWallLogicalVolume;
        G4VPhysicalVolume* shieldingSideWallPhysicalVolume;
        G4RotationMatrix* rotationMatrix;

};

#endif