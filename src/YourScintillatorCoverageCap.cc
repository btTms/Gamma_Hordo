#include "YourScintillatorCoverageCap.hh"

YourScintillatorCoverageCap::YourScintillatorCoverageCap() {
    this->pRmin = 0.0 * mm;
    this->pRmax = 26.5 * mm;
    this->pDz = 0.5 * mm;
}

void YourScintillatorCoverageCap::Build(G4LogicalVolume* motherVolume, G4Material* material, G4ThreeVector translate) {
    this->scintillatorCoverageCapVolume = new G4Tubs("ScintillatorCoverageCap", this->pRmin, this->pRmax, this->pDz, 0.0 * deg, 360.0 * deg);
    this->scintillatorCoverageCapLogicalVolume = new G4LogicalVolume(this->scintillatorCoverageCapVolume, material, "ScintillatorCoverageCapLogical");
    this->scintillatorCoverageCapPhysicalVolume = new G4PVPlacement(nullptr, translate, this->scintillatorCoverageCapLogicalVolume, "ScintillatorCoverageCapPhysical", motherVolume, false, 0);
    
    this->InitialiseAttributes();
}

void YourScintillatorCoverageCap::InitialiseAttributes() {
    G4VisAttributes* scintillatorCoverageCapVisAttributes = new G4VisAttributes(G4Colour(0.902, 0.761, 0.435, 1.0)); // brownish color
    scintillatorCoverageCapVisAttributes->SetVisibility(true);
    scintillatorCoverageCapVisAttributes->SetForceSolid(true);
    this->scintillatorCoverageCapLogicalVolume->SetVisAttributes(scintillatorCoverageCapVisAttributes);
}

YourScintillatorCoverageCap::~YourScintillatorCoverageCap() {
    delete this->scintillatorCoverageCapVolume;
    delete this->scintillatorCoverageCapLogicalVolume;
    delete this->scintillatorCoverageCapPhysicalVolume;
}