#pragma once
#ifndef _DB_OBJ_INCLUDED_
#define _DB_OBJ_INCLUDED_


class DbObjImpl;

#define DB_DECLARE_MEM(ClassName)\
protected:                           \
  ClassName(DbObjImpl* pImpl);       \
public:                              \
RX_DECLARE_MEMBERS (ClassName)

#define RX_DECLARE_MEM(ClassName)\
    RX_DECLARE_MEM_GENERIC(OdRxClass, ClassName)

#define ODRX_DECLARE_MEMBERS_GENERIC(ClassType, ClassName)\
public:                                                                                              \
                                                                                         \
  static OdSmartPtr<ClassName> cast(const OdRxObject* pObj)                                          \
  {                                                                                                  \
    if (pObj)                                                                                        \
      return OdSmartPtr<ClassName>(((ClassName*)pObj->queryX(ClassName::desc())), kOdRxObjAttach);   \
    return (ClassName*)0;                                                                            \
  }                                                                                                  \
                                                                                                     \
  static ClassType* g_pDesc;                                                                     **/  \
  static ClassType* desc();                                                                        **/  \
  virtual ClassType* isA() const;                                                            \
  virtual OdRxObject* queryX(const OdRxClass* protocolClass) const;                            \
  static OdRxObjectPtr pseudoConstructor();                                                          \
   static OdSmartPtr<ClassName> createObject()                                                       \
  { if (!desc()) throw OdError(eNotInitializedYet); return desc()->create(); }                       \
                                                                                                     \         \
  static void rxInit();                                                                              \
  static void rxInit(AppNameChangeFuncPtr appNameChangeFunc);                                        \
                                                                                            \
  static void rxUninit()

#endif //_ODDBXOBJECT_INCLUDED_

