//* This file is part of the MOOSE framework
//* https://www.mooseframework.org
//*
//* All rights reserved, see COPYRIGHT for full restrictions
//* https://github.com/idaholab/moose/blob/master/COPYRIGHT
//*
//* Licensed under LGPL 2.1, please see LICENSE for details
//* https://www.gnu.org/licenses/lgpl-2.1.html
#include "hpTestApp.h"
#include "hpApp.h"
#include "Moose.h"
#include "AppFactory.h"
#include "MooseSyntax.h"
#include "ModulesApp.h"

InputParameters
hpTestApp::validParams()
{
  InputParameters params = hpApp::validParams();
  return params;
}

hpTestApp::hpTestApp(InputParameters parameters) : MooseApp(parameters)
{
  hpTestApp::registerAll(
      _factory, _action_factory, _syntax, getParam<bool>("allow_test_objects"));
}

hpTestApp::~hpTestApp() {}

void
hpTestApp::registerAll(Factory & f, ActionFactory & af, Syntax & s, bool use_test_objs)
{
  hpApp::registerAll(f, af, s);
  if (use_test_objs)
  {
    Registry::registerObjectsTo(f, {"hpTestApp"});
    Registry::registerActionsTo(af, {"hpTestApp"});
  }
}

void
hpTestApp::registerApps()
{
  registerApp(hpApp);
  registerApp(hpTestApp);
}

/***************************************************************************************************
 *********************** Dynamic Library Entry Points - DO NOT MODIFY ******************************
 **************************************************************************************************/
// External entry point for dynamic application loading
extern "C" void
hpTestApp__registerAll(Factory & f, ActionFactory & af, Syntax & s)
{
  hpTestApp::registerAll(f, af, s);
}
extern "C" void
hpTestApp__registerApps()
{
  hpTestApp::registerApps();
}
