#ifndef __DALI_CSHARP_BINDER_WEB_VIEW_SIGNAL_CONVERTER_H__
#define __DALI_CSHARP_BINDER_WEB_VIEW_SIGNAL_CONVERTER_H__
/*
 * Copyright (c) 2021 Samsung Electronics Co., Ltd.
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 * http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 *
 */

// EXTERNAL INCLUDES
#include <dali-toolkit/devel-api/controls/web-view/web-view.h>
#include <dali/public-api/signals/connection-tracker.h>

/* Callback for returning strings to C# without leaking memory */
typedef char* (SWIGSTDCALL* SWIG_CSharpStringHelperCallback)(const char*);
extern SWIG_CSharpStringHelperCallback SWIG_csharp_string_callback;

namespace SignalConverter
{

// Proxy class of WebViewPageLoadSignal.
// WebViewPageLoadSignal has an argument of std::string type which is not
// supported at C# side. The purpose of this class is to convert signal argument
// of string type safely.
class WebViewPageLoadSignal : public Dali::ConnectionTracker
{
public:
  using NativeSignalType = Dali::Signal<void(Dali::Toolkit::WebView, const std::string&)>;
  using ProxySignalType = Dali::Signal<void(Dali::Toolkit::WebView, char*)>;
  using CallbackType = void (*)(Dali::Toolkit::WebView, char*);

  WebViewPageLoadSignal(NativeSignalType* signal) : mNativeSignalPtr(signal)
  {
  }

  ~WebViewPageLoadSignal()
  {
    if (!mProxySignal.Empty())
    {
      mNativeSignalPtr->Disconnect(this, &SignalConverter::WebViewPageLoadSignal::OnEmit);
    }
  }

  void Connect(CallbackType csharpCallback)
  {
    if (mNativeSignalPtr->Empty())
    {
      mNativeSignalPtr->Connect(this, &SignalConverter::WebViewPageLoadSignal::OnEmit);
    }
    mProxySignal.Connect(csharpCallback);
  }

  void Disconnect(CallbackType csharpCallback)
  {
    mProxySignal.Disconnect(csharpCallback);
    if (mProxySignal.Empty())
    {
      mNativeSignalPtr->Disconnect(this, &SignalConverter::WebViewPageLoadSignal::OnEmit);
    }
  }

  void OnEmit(Dali::Toolkit::WebView webview, const std::string& url)
  {
    // Safe string conversion
    mProxySignal.Emit(webview, SWIG_csharp_string_callback(url.c_str()));
  }

private:
  NativeSignalType *mNativeSignalPtr;
  ProxySignalType mProxySignal;
};

// Proxy class of WebViewScrollEdgeReachedSignal.
// WebViewScrollEdgeReachedSignal has an argument of enum type which is not
// supported at C# side. The purpose of this class is to convert signal argument
// of enum type safely.
class WebViewScrollEdgeReachedSignal : public Dali::ConnectionTracker
{
public:
  using NativeSignalType = Dali::Signal<void(Dali::Toolkit::WebView, Dali::WebEnginePlugin::ScrollEdge)>;
  using ProxySignalType = Dali::Signal<void(Dali::Toolkit::WebView, int)>;
  using CallbackType = void (*)(Dali::Toolkit::WebView, int);

  WebViewScrollEdgeReachedSignal(NativeSignalType *signal) : mNativeSignalPtr(signal)
  {
  }

  ~WebViewScrollEdgeReachedSignal()
  {
    if (!mProxySignal.Empty())
    {
      mNativeSignalPtr->Disconnect(this, &SignalConverter::WebViewScrollEdgeReachedSignal::OnEmit);
    }
  }

  void Connect(CallbackType csharpCallback)
  {
    if (mNativeSignalPtr->Empty())
    {
      mNativeSignalPtr->Connect(this, &SignalConverter::WebViewScrollEdgeReachedSignal::OnEmit);
    }
    mProxySignal.Connect(csharpCallback);
  }

  void Disconnect(CallbackType csharpCallback)
  {
    mProxySignal.Disconnect(csharpCallback);
    if (mProxySignal.Empty())
    {
      mNativeSignalPtr->Disconnect(this, &SignalConverter::WebViewScrollEdgeReachedSignal::OnEmit);
    }
  }

  void OnEmit(Dali::Toolkit::WebView webview, Dali::WebEnginePlugin::ScrollEdge edge)
  {
    mProxySignal.Emit(webview, static_cast<int>(edge));
  }

private:
  NativeSignalType* mNativeSignalPtr;
  ProxySignalType   mProxySignal;
};

// Proxy class of WebViewUrlChangedSignal.
// WebViewUrlChangedSignal has an argument of string type which is not supported at C# side.
// The purpose of this class is to convert signal argument of string type safely.
class WebViewUrlChangedSignal : public Dali::ConnectionTracker
{
public:
  using NativeSignalType = Dali::Signal<void(Dali::Toolkit::WebView, const std::string&)>;
  using ProxySignalType = Dali::Signal<void(Dali::Toolkit::WebView, char*)>;
  using CallbackType = void (*)(Dali::Toolkit::WebView, char*);

  WebViewUrlChangedSignal(NativeSignalType* signal)
    : mNativeSignalPtr(signal)
  {
  }

  ~WebViewUrlChangedSignal()
  {
    if (!mProxySignal.Empty())
    {
      mNativeSignalPtr->Disconnect(this, &SignalConverter::WebViewUrlChangedSignal::OnEmit);
    }
  }

  void Connect(CallbackType csharpCallback)
  {
    if ( mNativeSignalPtr->Empty() )
    {
      mNativeSignalPtr->Connect(this, &SignalConverter::WebViewUrlChangedSignal::OnEmit);
    }
    mProxySignal.Connect(csharpCallback);
  }

  void Disconnect(CallbackType csharpCallback)
  {
    mProxySignal.Disconnect(csharpCallback);
    if (mProxySignal.Empty())
    {
      mNativeSignalPtr->Disconnect(this, &SignalConverter::WebViewUrlChangedSignal::OnEmit);
    }
  }

  void OnEmit(Dali::Toolkit::WebView webview, const std::string& url)
  {
    mProxySignal.Emit(webview, SWIG_csharp_string_callback(url.c_str()));
  }

private:
  NativeSignalType* mNativeSignalPtr;
  ProxySignalType   mProxySignal;
};

// Proxy template class of WebViewProxySignal with a std::shared_ptr argument.
// WebViewProxySignal has an argument of std::shared_ptr type which is not supported at C# side.
// The purpose of this class is to convert signal argument of std::shared_ptr type safely.
template <class SignalArgumentType>
class WebViewProxySignal : public Dali::ConnectionTracker
{
public:
  using NativeSignalType = Dali::Signal<void(Dali::Toolkit::WebView, std::shared_ptr<SignalArgumentType>)>;
  using ProxySignalType = Dali::Signal<void(Dali::Toolkit::WebView, SignalArgumentType*)>;
  using CallbackType = void (*)(Dali::Toolkit::WebView, SignalArgumentType*);

  WebViewProxySignal(NativeSignalType* signal)
    : mNativeSignalPtr(signal)
  {
  }

  ~WebViewProxySignal()
  {
    if (!mProxySignal.Empty())
    {
      mNativeSignalPtr->Disconnect(this, &SignalConverter::WebViewProxySignal<SignalArgumentType>::OnEmit);
    }
  }

  void Connect(CallbackType csharpCallback)
  {
    if (mNativeSignalPtr->Empty())
    {
      mNativeSignalPtr->Connect(this, &SignalConverter::WebViewProxySignal<SignalArgumentType>::OnEmit);
    }
    mProxySignal.Connect(csharpCallback);
  }

  void Disconnect(CallbackType csharpCallback)
  {
    mProxySignal.Disconnect(csharpCallback);
    if (mProxySignal.Empty())
    {
      mNativeSignalPtr->Disconnect(this, &SignalConverter::WebViewProxySignal<SignalArgumentType>::OnEmit);
    }
  }

  void OnEmit(Dali::Toolkit::WebView webview, std::shared_ptr<SignalArgumentType> argument)
  {
    mArgumentSharedPtr = std::move(argument);
    mProxySignal.Emit(webview, mArgumentSharedPtr.get());
  }

private:
  NativeSignalType* mNativeSignalPtr;
  ProxySignalType   mProxySignal;
  std::shared_ptr<SignalArgumentType> mArgumentSharedPtr;
};

} // namespace SignalConverter

#endif // __DALI_CSHARP_BINDER_WEB_VIEW_SIGNAL_CONVERTER_H__
