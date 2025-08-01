#ifndef YOURPRIMARYGENERATOR_HH
#define YOURPRIMARYGENERATOR_HH


#include "G4VUserPrimaryGeneratorAction.hh"
#include "G4ParticleGun.hh"
#include "G4GeneralParticleSource.hh"


class YourPrimaryGeneratorAction : public G4VUserPrimaryGeneratorAction {
public:


    YourPrimaryGeneratorAction();
    virtual ~YourPrimaryGeneratorAction();

    virtual void GeneratePrimaries(G4Event* anEvent);

private:
    //G4ParticleGun* fPGun;
    G4GeneralParticleSource* fGps;

};
#endif