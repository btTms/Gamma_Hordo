#ifndef YOURCOLLIMATOR_HH
#define YOURCOLLIMATOR_HH

#include <G4LogicalVolume.hh>
#include <G4RotationMatrix.hh>
#include <G4ThreeVector.hh>
#include <G4Tubs.hh>
#include <G4Material.hh>
#include <G4PVPlacement.hh>
#include <G4Types.hh>
#include <G4VisAttributes.hh>
#include <G4SystemOfUnits.hh>
#include <G4Trap.hh>

#include "YourCollimatorLayer.hh"

class YourCollimator{
    public:
        YourCollimator(G4double rotationAngle, G4double pRmin1, G4double pRmax1, G4double pDz1,
                                               G4double pRmin2, G4double pRmax2, G4double pDz2,
                                               G4double pRmin3, G4double pRmax3, G4double pDz3);
        ~YourCollimator();

        void Build(G4LogicalVolume* motherVolume, G4Material* collimatorLayer1Material, 
                   G4Material* collimatorLayer2Material, G4Material* collimatorLayer3Material,
                   G4ThreeVector translation);

    private:
        YourCollimatorLayer* collimatorLayer1, *collimatorLayer2, *collimatorLayer3;
};


#endif