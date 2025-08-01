#include "YourBarrel.hh"
#include <G4LogicalVolume.hh>

YourBarrel::YourBarrel() {
    this->barrelContent = new YourBarrelContent();
    this->barrelSideWall = new YourBarrelSideWall();
    this->topWall = new YourBarrelVerticalWall();
    this->bottomWall = new YourBarrelVerticalWall();

    this->bottomWallTranslation = G4ThreeVector(0.0, 0.75 * mm, 0.0);
    this->topWallTranslation = G4ThreeVector(0.0, 878.25 * mm, 0.0);
}

void YourBarrel::Build(G4LogicalVolume* contentMotherLogicalVolume, G4Material* contentBuildMaterial,
                       G4LogicalVolume* sideWallMotherLogicalVolume, G4Material* sideWallBuildMaterial,
                       G4LogicalVolume* topWallMotherLogicalVolume, G4Material* topWallBuildMaterial,
                       G4LogicalVolume* bottomWallMotherLogicalVolume, G4Material* bottomWallBuildMaterial)
{
    this->barrelContent->Build(contentMotherLogicalVolume, contentBuildMaterial);
    this->barrelSideWall->Build(sideWallMotherLogicalVolume, sideWallBuildMaterial);
    this->topWall->Build(topWallMotherLogicalVolume, topWallBuildMaterial, this->topWallTranslation);
    this->bottomWall->Build(bottomWallMotherLogicalVolume, bottomWallBuildMaterial, this->bottomWallTranslation);
}

YourBarrel::~YourBarrel() {
    delete this->barrelContent;
    delete this->barrelSideWall;
    delete this->topWall;
    delete this->bottomWall;
}