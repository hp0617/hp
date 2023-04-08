#include "hpApp.h"
#include "Moose.h"
#include "AppFactory.h"
#include "ModulesApp.h"
#include "MooseSyntax.h"

InputParameters
hpApp::validParams()
{
  InputParameters params = MooseApp::validParams();

  return params;
}

hpApp::hpApp(InputParameters parameters) : MooseApp(parameters)
{
  hpApp::registerAll(_factory, _action_factory, _syntax);
}

hpApp::~hpApp() {}

void
hpApp::registerAll(Factory & f, ActionFactory & af, Syntax & syntax)
{
  ModulesApp::registerAll(f, af, syntax);
  Registry::registerObjectsTo(f, {"hpApp"});
  Registry::registerActionsTo(af, {"hpApp"});

  /* register custom execute flags, action syntax, etc. here */
}

void
hpApp::registerApps()
{
  registerApp(hpApp);
}

/***************************************************************************************************
 *********************** Dynamic Library Entry Points - DO NOT MODIFY ******************************
 **************************************************************************************************/
extern "C" void
hpApp__registerAll(Factory & f, ActionFactory & af, Syntax & s)
{
  hpApp::registerAll(f, af, s);
}
extern "C" void
hpApp__registerApps()
{
  hpApp::registerApps();
}
