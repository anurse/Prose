#include "pch.h"
#include "OverflowDocumentHost.h"
#include "DocumentHost.h"

using namespace Microsoft::WRL;

using namespace Windows::Foundation::Collections;

using namespace Prose::Controls;
using namespace Prose::Structure;

DocumentHost^ OverflowDocumentHost::RootHost::get() {
	Microsoft::WRL::ComPtr<IInspectable> objRaw(nullptr);
	_hostRef.As(&objRaw);
	return reinterpret_cast<DocumentHost^>(objRaw.Get());
}

TextStyle^ OverflowDocumentHost::GetBaseStyle() {
	return RootHost ? RootHost->GetBaseStyle() : nullptr;
}

void OverflowDocumentHost::Detach() {
	_hostRef = WeakRef(nullptr);
}

void OverflowDocumentHost::Attach(DocumentHost^ rootHost) {
	AsWeak(reinterpret_cast<IInspectable*>(rootHost), &_hostRef);
}

void OverflowDocumentHost::RecieveOverflow(IVectorView<BlockNode^>^ overflow) {
	if(!RootHost) {
		throw ref new Platform::FailureException("Invalid Operation: Cannot send overflow to an overflow document host until it has been attached");
	}
	_overflowTree = ref new StructureTree();
	
	for(auto BlockNode : overflow) {
		_overflowTree->Blocks->Append(BlockNode);
	}

	InvalidateMeasure();
}

