#include "YourGround.hh"


YourGround::YourGround() {
    this->lengthX = 10.0 * m;
    this->lengthY = 100.0 * mm;
    this->lengthZ = 10.0 * m;

}

void YourGround::Build(G4LogicalVolume* motherLogicalVolume, G4Material* buildMaterial){
    this->groundVolume = new G4Box("GroundVolume", this->lengthX / 2, this->lengthY / 2, this->lengthZ / 2);
    this->groundLogicalVolume = new G4LogicalVolume(this->groundVolume, buildMaterial, "GroundLogicalVolume");
    this->groundPhysicalVolume = new G4PVPlacement(nullptr, G4ThreeVector(0, -350.0 * mm, 0), this->groundLogicalVolume, "GroundPhysicalVolume", motherLogicalVolume, false, 0);
    this->InitialiseAttributes();
}  

void YourGround::InitialiseAttributes() {

    G4VisAttributes* visAttributes = new G4VisAttributes(G4Color(0.5, 0.5, 0.5, 1.0));
    visAttributes->SetForceSolid(true);
    this->groundLogicalVolume->SetVisAttributes(visAttributes);
}

YourGround::~YourGround() {
    delete this->groundVolume;
    delete this->groundLogicalVolume;
    delete this->groundPhysicalVolume;
}