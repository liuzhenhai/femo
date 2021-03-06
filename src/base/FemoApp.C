#include "FemoApp.h"
#include "Moose.h"
#include "AppFactory.h"
#include "ModulesApp.h"
#include "MooseSyntax.h"

template<>
InputParameters validParams<FemoApp>()
{
  InputParameters params = validParams<MooseApp>();

  params.set<bool>("use_legacy_uo_initialization") = false;
  params.set<bool>("use_legacy_uo_aux_computation") = false;
  params.set<bool>("use_legacy_output_syntax") = false;

  return params;
}

FemoApp::FemoApp(InputParameters parameters) :
    MooseApp(parameters)
{
  Moose::registerObjects(_factory);
  ModulesApp::registerObjects(_factory);
  FemoApp::registerObjects(_factory);

  Moose::associateSyntax(_syntax, _action_factory);
  ModulesApp::associateSyntax(_syntax, _action_factory);
  FemoApp::associateSyntax(_syntax, _action_factory);
}

FemoApp::~FemoApp()
{
}

// External entry point for dynamic application loading
extern "C" void FemoApp__registerApps() { FemoApp::registerApps(); }
void
FemoApp::registerApps()
{
  registerApp(FemoApp);
}

// External entry point for dynamic object registration
extern "C" void FemoApp__registerObjects(Factory & factory) { FemoApp::registerObjects(factory); }
void
FemoApp::registerObjects(Factory & factory)
{
}

// External entry point for dynamic syntax association
extern "C" void FemoApp__associateSyntax(Syntax & syntax, ActionFactory & action_factory) { FemoApp::associateSyntax(syntax, action_factory); }
void
FemoApp::associateSyntax(Syntax & /*syntax*/, ActionFactory & /*action_factory*/)
{
}
