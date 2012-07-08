#pragma once

#include "Inline.h"

namespace Prose {
	namespace Structure {
		[Windows::UI::Xaml::Markup::ContentProperty(Name = "Text")]
		public ref class Run sealed :
			public Inline
		{
		public:
			Run(void);
			Run(Platform::String^);

			property Platform::String^ Text {
				Platform::String^ get() { return _text; }
				void set(Platform::String^ value) { _text = value; }
			};

			virtual property UINT32 Length {
				UINT32 get() override { return _text->Length(); }
			}

			virtual void Accept(DocumentVisitor^ visitor) override;
			virtual InlinePair^ Split(UINT32 localOffset) override;
		private:
			Platform::String^ _text;
		};
	}
}