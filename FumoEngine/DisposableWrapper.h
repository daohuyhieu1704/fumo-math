#pragma once

using namespace System;
using namespace System::Runtime::InteropServices;

namespace FumoWrapper
{
	template <typename T>
	public ref class DisposableWrapper : IDisposable
	{
	private:
		T* nativePtr;
	public:
		DisposableWrapper(T* ptr) : nativePtr(ptr)
		{
		}

		!DisposableWrapper()
		{
			delete nativePtr;
			nativePtr = nullptr;
		}

		virtual ~DisposableWrapper()
		{
			this->!DisposableWrapper();
		}

		T* GetNativePointer()
		{
			return nativePtr;
		}
	};
}