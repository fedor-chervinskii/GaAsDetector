#ifndef StepLimitPhysics_h
#define StepLimitPhysics_h 1

#include "G4VPhysicsConstructor.hh"
#include "globals.hh"

class StepLimitPhysics : public G4VPhysicsConstructor
{
public:
  StepLimitPhysics(G4int ver = 0, const G4String& name = "G4StepLimit");
  virtual ~StepLimitPhysics();

  virtual void ConstructParticle();
  virtual void ConstructProcess();

private:
  G4int  verbose;
};

#endif






