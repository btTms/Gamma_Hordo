#ifndef YOURSHIELDINGVERTICALWALL_HH
#define YOURSHIELDINGVERTICALWALL_HH

#include <G4LogicalVolume.hh>
#include <G4RotationMatrix.hh>
#include <G4Tubs.hh>
#include <G4Material.hh>
#include <G4PVPlacement.hh>
#include <G4VisAttributes.hh>
#include <G4SystemOfUnits.hh>

class YourShieldingVerticalWall{

    public:
        YourShieldingVerticalWall();
        ~YourShieldingVerticalWall();

        void Build(G4LogicalVolume* motherLogicalVolume, G4Material* buildMaterial, G4ThreeVector translation);

    private:
        void InitialiseAttributes();
        
        G4double pRmin, pRmax, pDz;
        G4Tubs* shieldingVerticalWallVolume;
        G4LogicalVolume* shieldingVerticalWallLogicalVolume;
        G4VPhysicalVolume* shieldingVerticalWallPhysicalVolume;
        G4RotationMatrix* rotationMatrix;

};


#endif