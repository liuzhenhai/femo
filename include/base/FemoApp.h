#ifndef FEMOAPP_H
#define FEMOAPP_H

#include "MooseApp.h"

class FemoApp;

template<>
InputParameters validParams<FemoApp>();

class FemoApp : public MooseApp
{
public:
  FemoApp(InputParameters parameters);
  virtual ~FemoApp();

  static void registerApps();
  static void registerObjects(Factory & factory);
  static void associateSyntax(Syntax & syntax, ActionFactory & action_factory);
};

#endif /* FEMOAPP_H */
