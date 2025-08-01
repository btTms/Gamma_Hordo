#include "YourExternalBackgroundSource.hh"

YourExternalBackgroundSource::YourExternalBackgroundSource() {
    this->pRmin = 1000 * mm;
    this->pRmax = 1200 * mm;
    this->pDz = 750.0 * mm;
    this->rotationMatrix = new G4RotationMatrix();
    this->rotationMatrix->rotateX(90.0 * deg);
}

void YourExternalBackgroundSource::Build(G4LogicalVolume* motherLogicalVolume, G4Material* buildMaterial){                                           
    this->externalBackgroundVolume = new G4Tubs("ExternalBackgroundSourceVolume", this->pRmin, this->pRmax, this->pDz, 0.0 * deg, 180.0 * deg);
    this->externalBackgroundLogicalVolume = new G4LogicalVolume(this->externalBackgroundVolume, buildMaterial, "ExternalBackroundSourceLogicalVolume");
    this->externalBackgroundPhysicalVolume = new G4PVPlacement(this->rotationMatrix, G4ThreeVector(0.0, 450.0 * mm, 0.0), this->externalBackgroundLogicalVolume, "ExternalBackgroundSourcePhysicalVolume", motherLogicalVolume, false, 0);
    this->InitialiseAttributes();
}  

void YourExternalBackgroundSource::InitialiseAttributes() {

    G4VisAttributes* visAttributes = new G4VisAttributes(G4Color(0.271, 0.271, 0.251, 1.0));
    visAttributes->SetForceSolid(true);
    this->externalBackgroundLogicalVolume->SetVisAttributes(visAttributes);
}

YourExternalBackgroundSource::~YourExternalBackgroundSource() {
    delete this->externalBackgroundVolume;
    delete this->externalBackgroundLogicalVolume;
    delete this->externalBackgroundPhysicalVolume;
}