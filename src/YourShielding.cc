#include "YourShielding.hh"


YourShielding::YourShielding() {
    this->sideWall = new YourShieldingSideWall();
    this->topWall = new YourShieldingVerticalWall();
    this->bottomWall = new YourShieldingVerticalWall();
    this->translationTopWall = G4ThreeVector(0, 1275.0 * mm,  0);
    this->translationBottomWall = G4ThreeVector(0, -275.0, 0.0 * mm);
}

void YourShielding::Build(G4LogicalVolume* sideWallMotherLogicalVolume, G4Material* sideWallbuildMaterial,
                          G4LogicalVolume* topWallMotherLogicalVolume, G4Material* topWallBuildMaterial,
                          G4LogicalVolume* bottomWallMotherLogicalVolume, G4Material* bottomWallBuildMaterial) {
    this->sideWall->Build(sideWallMotherLogicalVolume, sideWallbuildMaterial);
    this->topWall->Build(topWallMotherLogicalVolume, topWallBuildMaterial, this->translationTopWall);
    this->bottomWall->Build(bottomWallMotherLogicalVolume, bottomWallBuildMaterial, this->translationBottomWall);
}

YourShielding::~YourShielding() {
    delete this->sideWall;
    delete this->topWall;
    delete this->bottomWall;
}