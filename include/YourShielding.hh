#ifndef YOURSHIELDING_HH
#define YOURSHIELDING_HH

#include <G4LogicalVolume.hh>
#include <G4RotationMatrix.hh>
#include <G4ThreeVector.hh>
#include <G4Tubs.hh>
#include <G4Material.hh>
#include <G4PVPlacement.hh>
#include <G4VisAttributes.hh>
#include <G4SystemOfUnits.hh>

#include "YourShieldingSideWall.hh"
#include "YourShieldingVerticalWall.hh"

class YourShielding{

    public:
        YourShielding();
        ~YourShielding();

        void Build(G4LogicalVolume* sideWallMotherLogicalVolume, G4Material* sideWallbuildMaterial,
            G4LogicalVolume* topWallMotherLogicalVolume, G4Material* topWallBuildMaterial,
            G4LogicalVolume* bottomWallMotherLogicalVolume, G4Material* bottomWallBuildMaterial);

    private:

        YourShieldingSideWall* sideWall;
        YourShieldingVerticalWall* topWall;
        YourShieldingVerticalWall* bottomWall;

        G4ThreeVector translationTopWall, translationBottomWall;

};


#endif