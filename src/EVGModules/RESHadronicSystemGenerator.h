//____________________________________________________________________________
/*!

\class   genie::RESHadronicSystemGenerator

\brief   Generates the 'final state' hadronic system in v RES interactions.

         It adds the remnant nucleus (if any), the pre-selected resonance
         and the resonance decay products at the GHEP record. 
         Unlike the SPP thread, in the RES thread the resonance is specified
         at the time an interaction is selected but its decay products not
         (semi-inclusive resonance reactions). The off the mass-shell baryon
         resonance is decayed using a phase space generator. All kinematically
         available decay channels are being used (not just 1 pi channels).

         Is a concrete implementation of the EventRecordVisitorI interface.

\author  Costas Andreopoulos <C.V.Andreopoulos@rl.ac.uk>
         CCLRC, Rutherford Appleton Laboratory

\created November 23, 2004

*/
//____________________________________________________________________________

#ifndef _RES_HADRONIC_SYSTEM_GENERATOR_H_
#define _RES_HADRONIC_SYSTEM_GENERATOR_H_

#include "EVGModules/HadronicSystemGenerator.h"

namespace genie {

class DecayModelI;

class RESHadronicSystemGenerator : public HadronicSystemGenerator {

public :
  RESHadronicSystemGenerator();
  RESHadronicSystemGenerator(string config);
  ~RESHadronicSystemGenerator();

  //-- implement the EventRecordVisitorI interface
  void ProcessEventRecord(GHepRecord * event_rec) const;

  //-- overload the Algorithm::Configure() methods to load private data
  //   members from configuration options
  void Configure(const Registry & config);
  void Configure(string config);

private:

  void LoadConfig                (void);
  int  GetResonancePdgCode       (GHepRecord * evrec) const;
  void AddResonance              (GHepRecord * evrec, int pdgc) const;
  void AddResonanceDecayProducts (GHepRecord * evrec, int pdgc) const;

  const DecayModelI * fResonanceDecayer;
};

}      // genie namespace

#endif // _RES_HADRONIC_SYSTEM_GENERATOR_H_
