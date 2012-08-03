#pragma once

#include "..\Structure\StructureTree.h"
#include "DocumentNode.h"

namespace Prose {
	namespace Controls {
		namespace WFM = Windows::Foundation::Metadata;
		namespace WUX = Windows::UI::Xaml;
		namespace WFC = Windows::Foundation::Collections;

		[WFM::WebHostHidden]
		[WUX::Markup::ContentProperty(Name = "Children")]
		public ref class Document sealed :
			public StylableNode
		{
		public:
			Document(void);

			property WFC::IVector<BlockNode^>^ Children {
				WFC::IVector<BlockNode^>^ get() { return _children; }
			}

		internal:
			Prose::Structure::StructureTree^ CreateStructureTree();

		private:
			WFC::IVector<BlockNode^>^ _children;
		};
	}
}