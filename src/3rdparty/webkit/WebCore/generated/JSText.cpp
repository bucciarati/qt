/*
    This file is part of the WebKit open source project.
    This file has been generated by generate-bindings.pl. DO NOT MODIFY!

    This library is free software; you can redistribute it and/or
    modify it under the terms of the GNU Library General Public
    License as published by the Free Software Foundation; either
    version 2 of the License, or (at your option) any later version.

    This library is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
    Library General Public License for more details.

    You should have received a copy of the GNU Library General Public License
    along with this library; see the file COPYING.LIB.  If not, write to
    the Free Software Foundation, Inc., 51 Franklin Street, Fifth Floor,
    Boston, MA 02110-1301, USA.
*/

#include "config.h"
#include "JSText.h"

#include "ExceptionCode.h"
#include "JSText.h"
#include "KURL.h"
#include "Text.h"
#include <runtime/Error.h>
#include <runtime/JSString.h>
#include <wtf/GetPtr.h>

using namespace JSC;

namespace WebCore {

ASSERT_CLASS_FITS_IN_CELL(JSText);

/* Hash table */

static const HashTableValue JSTextTableValues[3] =
{
    { "wholeText", DontDelete|ReadOnly, (intptr_t)jsTextWholeText, (intptr_t)0 },
    { "constructor", DontEnum|ReadOnly, (intptr_t)jsTextConstructor, (intptr_t)0 },
    { 0, 0, 0, 0 }
};

static JSC_CONST_HASHTABLE HashTable JSTextTable =
#if ENABLE(PERFECT_HASH_SIZE)
    { 63, JSTextTableValues, 0 };
#else
    { 5, 3, JSTextTableValues, 0 };
#endif

/* Hash table for constructor */

static const HashTableValue JSTextConstructorTableValues[1] =
{
    { 0, 0, 0, 0 }
};

static JSC_CONST_HASHTABLE HashTable JSTextConstructorTable =
#if ENABLE(PERFECT_HASH_SIZE)
    { 0, JSTextConstructorTableValues, 0 };
#else
    { 1, 0, JSTextConstructorTableValues, 0 };
#endif

class JSTextConstructor : public DOMConstructorObject {
public:
    JSTextConstructor(ExecState* exec, JSDOMGlobalObject* globalObject)
        : DOMConstructorObject(JSTextConstructor::createStructure(globalObject->objectPrototype()), globalObject)
    {
        putDirect(exec->propertyNames().prototype, JSTextPrototype::self(exec, globalObject), None);
    }
    virtual bool getOwnPropertySlot(ExecState*, const Identifier&, PropertySlot&);
    virtual bool getOwnPropertyDescriptor(ExecState*, const Identifier&, PropertyDescriptor&);
    virtual const ClassInfo* classInfo() const { return &s_info; }
    static const ClassInfo s_info;

    static PassRefPtr<Structure> createStructure(JSValue proto) 
    { 
        return Structure::create(proto, TypeInfo(ObjectType, StructureFlags)); 
    }
    
protected:
    static const unsigned StructureFlags = OverridesGetOwnPropertySlot | ImplementsHasInstance | DOMConstructorObject::StructureFlags;
};

const ClassInfo JSTextConstructor::s_info = { "TextConstructor", 0, &JSTextConstructorTable, 0 };

bool JSTextConstructor::getOwnPropertySlot(ExecState* exec, const Identifier& propertyName, PropertySlot& slot)
{
    return getStaticValueSlot<JSTextConstructor, DOMObject>(exec, &JSTextConstructorTable, this, propertyName, slot);
}

bool JSTextConstructor::getOwnPropertyDescriptor(ExecState* exec, const Identifier& propertyName, PropertyDescriptor& descriptor)
{
    return getStaticValueDescriptor<JSTextConstructor, DOMObject>(exec, &JSTextConstructorTable, this, propertyName, descriptor);
}

/* Hash table for prototype */

static const HashTableValue JSTextPrototypeTableValues[3] =
{
    { "splitText", DontDelete|Function, (intptr_t)jsTextPrototypeFunctionSplitText, (intptr_t)1 },
    { "replaceWholeText", DontDelete|Function, (intptr_t)jsTextPrototypeFunctionReplaceWholeText, (intptr_t)1 },
    { 0, 0, 0, 0 }
};

static JSC_CONST_HASHTABLE HashTable JSTextPrototypeTable =
#if ENABLE(PERFECT_HASH_SIZE)
    { 1, JSTextPrototypeTableValues, 0 };
#else
    { 4, 3, JSTextPrototypeTableValues, 0 };
#endif

const ClassInfo JSTextPrototype::s_info = { "TextPrototype", 0, &JSTextPrototypeTable, 0 };

JSObject* JSTextPrototype::self(ExecState* exec, JSGlobalObject* globalObject)
{
    return getDOMPrototype<JSText>(exec, globalObject);
}

bool JSTextPrototype::getOwnPropertySlot(ExecState* exec, const Identifier& propertyName, PropertySlot& slot)
{
    return getStaticFunctionSlot<JSObject>(exec, &JSTextPrototypeTable, this, propertyName, slot);
}

bool JSTextPrototype::getOwnPropertyDescriptor(ExecState* exec, const Identifier& propertyName, PropertyDescriptor& descriptor)
{
    return getStaticFunctionDescriptor<JSObject>(exec, &JSTextPrototypeTable, this, propertyName, descriptor);
}

const ClassInfo JSText::s_info = { "Text", &JSCharacterData::s_info, &JSTextTable, 0 };

JSText::JSText(NonNullPassRefPtr<Structure> structure, JSDOMGlobalObject* globalObject, PassRefPtr<Text> impl)
    : JSCharacterData(structure, globalObject, impl)
{
}

JSObject* JSText::createPrototype(ExecState* exec, JSGlobalObject* globalObject)
{
    return new (exec) JSTextPrototype(JSTextPrototype::createStructure(JSCharacterDataPrototype::self(exec, globalObject)));
}

bool JSText::getOwnPropertySlot(ExecState* exec, const Identifier& propertyName, PropertySlot& slot)
{
    return getStaticValueSlot<JSText, Base>(exec, &JSTextTable, this, propertyName, slot);
}

bool JSText::getOwnPropertyDescriptor(ExecState* exec, const Identifier& propertyName, PropertyDescriptor& descriptor)
{
    return getStaticValueDescriptor<JSText, Base>(exec, &JSTextTable, this, propertyName, descriptor);
}

JSValue jsTextWholeText(ExecState* exec, const Identifier&, const PropertySlot& slot)
{
    JSText* castedThis = static_cast<JSText*>(asObject(slot.slotBase()));
    UNUSED_PARAM(exec);
    Text* imp = static_cast<Text*>(castedThis->impl());
    return jsString(exec, imp->wholeText());
}

JSValue jsTextConstructor(ExecState* exec, const Identifier&, const PropertySlot& slot)
{
    JSText* domObject = static_cast<JSText*>(asObject(slot.slotBase()));
    return JSText::getConstructor(exec, domObject->globalObject());
}
JSValue JSText::getConstructor(ExecState* exec, JSGlobalObject* globalObject)
{
    return getDOMConstructor<JSTextConstructor>(exec, static_cast<JSDOMGlobalObject*>(globalObject));
}

JSValue JSC_HOST_CALL jsTextPrototypeFunctionSplitText(ExecState* exec, JSObject*, JSValue thisValue, const ArgList& args)
{
    UNUSED_PARAM(args);
    if (!thisValue.inherits(&JSText::s_info))
        return throwError(exec, TypeError);
    JSText* castedThisObj = static_cast<JSText*>(asObject(thisValue));
    Text* imp = static_cast<Text*>(castedThisObj->impl());
    ExceptionCode ec = 0;
    int offset = args.at(0).toInt32(exec);
    if (offset < 0) {
        setDOMException(exec, INDEX_SIZE_ERR);
        return jsUndefined();
    }


    JSC::JSValue result = toJS(exec, castedThisObj->globalObject(), WTF::getPtr(imp->splitText(offset, ec)));
    setDOMException(exec, ec);
    return result;
}

JSValue JSC_HOST_CALL jsTextPrototypeFunctionReplaceWholeText(ExecState* exec, JSObject*, JSValue thisValue, const ArgList& args)
{
    UNUSED_PARAM(args);
    if (!thisValue.inherits(&JSText::s_info))
        return throwError(exec, TypeError);
    JSText* castedThisObj = static_cast<JSText*>(asObject(thisValue));
    Text* imp = static_cast<Text*>(castedThisObj->impl());
    ExceptionCode ec = 0;
    const UString& content = args.at(0).toString(exec);


    JSC::JSValue result = toJS(exec, castedThisObj->globalObject(), WTF::getPtr(imp->replaceWholeText(content, ec)));
    setDOMException(exec, ec);
    return result;
}


}
