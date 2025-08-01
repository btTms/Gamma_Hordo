#include "YourShieldingSideWall.hh"

YourShieldingSideWall::YourShieldingSideWall() {
    this->pRmin = 570.0 * mm;
    this->pRmax = 620.0 * mm;
    this->pDz = 750.0 * mm;
    this->rotationMatrix = new G4RotationMatrix();
    this->rotationMatrix->rotateX(90.0 * deg);
}

void YourShieldingSideWall::Build(G4LogicalVolume* motherLogicalVolume, G4Material* buildMaterial){
    this->barrelSideWallVolume = new G4Tubs("BarrelSideWallVolume", this->pRmin, this->pRmax, this->pDz, 0.0 * deg, 10.0 * deg);
    this->shieldingSideWallLogicalVolume = new G4LogicalVolume(this->barrelSideWallVolume, buildMaterial, "ShieldingSideWallLogicalVolume");
    this->shieldingSideWallPhysicalVolume = new G4PVPlacement(this->rotationMatrix, G4ThreeVector(0, 500.0 * mm, 0), this->shieldingSideWallLogicalVolume, "ShieldingSideWallPhysicalVolume", motherLogicalVolume, false, 0);
    this->InitialiseAttributes();
}

void YourShieldingSideWall::InitialiseAttributes() {
    G4VisAttributes* visAttributes = new G4VisAttributes(G4Color(0.839, 0.839, 0.839, 1.0));
    visAttributes->SetForceSolid(true);
    this->shieldingSideWallLogicalVolume->SetVisAttributes(visAttributes);
}

YourShieldingSideWall::~YourShieldingSideWall() {
    delete this->barrelSideWallVolume;
    delete this->shieldingSideWallLogicalVolume;
    delete this->shieldingSideWallPhysicalVolume;
    delete this->rotationMatrix;
}

