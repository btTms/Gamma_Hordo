#include "YourDetectorBody.hh"


YourDetectorBody::YourDetectorBody(){
    this->pRmin = 0.0 * mm;
    this->pRmax = 32.5 * mm;
    this->pDz = 160.0 * mm;
}

void YourDetectorBody::Build(G4LogicalVolume* motherVolume, G4Material* material, G4ThreeVector translate) {
    this->detectorBodyVolume = new G4Tubs("DetectorBody", this->pRmin, this->pRmax, this->pDz, 0.0 * deg, 180.0 * deg);
    this->detectorBodyLogicalVolume = new G4LogicalVolume(this->detectorBodyVolume, material, "DetectorBodyLogical");
    this->detectorBodyPhysicalVolume = new G4PVPlacement(nullptr, translate, this->detectorBodyLogicalVolume, "DetectorBodyPhysical", motherVolume, false, 0);
    
    this->InitialiseAttributes();
}

void YourDetectorBody::InitialiseAttributes() {
    G4VisAttributes* visAttributes = new G4VisAttributes(G4Colour(0.671, 0.141, 0.133, 1.0)); // redish, brownish color
    visAttributes->SetForceSolid(true);
    this->detectorBodyLogicalVolume->SetVisAttributes(visAttributes);
}

YourDetectorBody::~YourDetectorBody(){
    delete this->detectorBodyVolume;
    delete this->detectorBodyLogicalVolume;
    delete this->detectorBodyPhysicalVolume;
}