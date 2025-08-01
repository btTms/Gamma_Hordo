#include "YourShieldingVerticalWall.hh"


YourShieldingVerticalWall::YourShieldingVerticalWall() {
    this->pRmin = 0.0 * mm;
    this->pRmax = 620.0 * mm;
    this->pDz = 25.0 * mm;
    this->rotationMatrix = new G4RotationMatrix();
    this->rotationMatrix->rotateX(90.0 * deg);
}

void YourShieldingVerticalWall::Build(G4LogicalVolume* motherLogicalVolume, G4Material* buildMaterial, G4ThreeVector translation){
    this->shieldingVerticalWallVolume = new G4Tubs("ShieldingVerticalWallVolume", this->pRmin, this->pRmax, this->pDz, 0.0 * deg, 10.0 * deg);
    this->shieldingVerticalWallLogicalVolume = new G4LogicalVolume(this->shieldingVerticalWallVolume, buildMaterial, "ShieldingVerticalWallLogicalVolume");
    this->shieldingVerticalWallPhysicalVolume = new G4PVPlacement(this->rotationMatrix, translation, this->shieldingVerticalWallLogicalVolume, "ShieldingVerticalWallPhysicalVolume", motherLogicalVolume, false, 0);
    this->InitialiseAttributes();
}

void YourShieldingVerticalWall::InitialiseAttributes() {
    G4VisAttributes* visAttributes = new G4VisAttributes(G4Color(0.839, 0.839, 0.839, 1.0));
    visAttributes->SetForceSolid(true);
    this->shieldingVerticalWallLogicalVolume->SetVisAttributes(visAttributes);
}

YourShieldingVerticalWall::~YourShieldingVerticalWall() {
    delete this->shieldingVerticalWallVolume;
    delete this->shieldingVerticalWallLogicalVolume;
    delete this->shieldingVerticalWallPhysicalVolume;
    delete this->rotationMatrix;
}