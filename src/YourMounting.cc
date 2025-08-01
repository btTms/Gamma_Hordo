#include "YourMounting.hh"

YourMounting::YourMounting() {
    this->pRmin = 0.0 * m;
    this->pRmax = 257.4 * mm;
    this->pDz = 125.0 * mm;
    this->rotationMatrix = new G4RotationMatrix();
    this->rotationMatrix->rotateX(90.0 * deg);
}


void YourMounting::Build(G4LogicalVolume* motherLogicalVolume, G4Material* buildMaterial){                                              // 360
    this->mountingVolume = new G4Tubs("MountingVolume", this->pRmin, this->pRmax, this->pDz, 0.0 * deg, 180.0 * deg);
    this->mountingLogicalVolume = new G4LogicalVolume(this->mountingVolume, buildMaterial, "MountingLogicalVolume");
    this->mountingPhysicalVolume = new G4PVPlacement(this->rotationMatrix, G4ThreeVector(0, -125.0 * mm, 0), this->mountingLogicalVolume, "MountingPhysicalVolume", motherLogicalVolume, false, 0);
    this->InitialiseAttributes();
}  

void YourMounting::InitialiseAttributes() {

    G4VisAttributes* visAttributes = new G4VisAttributes(G4Color(0.271, 0.271, 0.251, 1.0));
    visAttributes->SetForceSolid(true);
    this->mountingLogicalVolume->SetVisAttributes(visAttributes);
}

YourMounting::~YourMounting() {
    delete this->mountingVolume;
    delete this->mountingLogicalVolume;
    delete this->mountingPhysicalVolume;
}