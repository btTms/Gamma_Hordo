#include "YourSideReflectionLayer.hh"


YourSideReflexionLayer::YourSideReflexionLayer() {
    this->pRmin = 25.0 * mm;
    this->pRmax = 25.5 * mm;
    this->pDz = 100 * mm;
}

void YourSideReflexionLayer::Build(G4LogicalVolume* motherLogicalVolume, G4Material* buildMaterial){
    this->sideReflectionLayerVolume = new G4Tubs("sideReflectionLayerVolume", this->pRmin, this->pRmax, this->pDz, 0.0 * deg, 180.0 * deg);
    this->sideReflectionLayerLogicalVolume = new G4LogicalVolume(this->sideReflectionLayerVolume, buildMaterial, "SideReflectionLayerLogicalVolume");
    this->sideReflectionLayerPhysicalVolume = new G4PVPlacement(nullptr, G4ThreeVector(0, 0 * mm, 0), this->sideReflectionLayerLogicalVolume, "ShieldingSideWallPhysicalVolume", motherLogicalVolume, false, 0);
    this->InitialiseAttributes();
}

void YourSideReflexionLayer::InitialiseAttributes() {
    G4VisAttributes* sideReflectionLayerVisAttributes = new G4VisAttributes(G4Colour(1.0, 1.0, 1.0, 1.0));
    sideReflectionLayerVisAttributes->SetForceSolid(true);
    this->sideReflectionLayerLogicalVolume->SetVisAttributes(sideReflectionLayerVisAttributes);
}

YourSideReflexionLayer::~YourSideReflexionLayer() {
    delete this->sideReflectionLayerVolume;
    delete this->sideReflectionLayerLogicalVolume;
    delete this->sideReflectionLayerPhysicalVolume;
}