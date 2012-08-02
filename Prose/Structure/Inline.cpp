#include "pch.h"
#include "Inline.h"
#include "StructureVisitor.h"
#include "..\TextFormat.h"

using namespace Windows::UI::Text;
using namespace Windows::UI::Xaml;
using namespace Windows::UI::Xaml::Media;

using namespace Prose;
using namespace Prose::Events;
using namespace Prose::Structure;

using namespace Platform;

void Inline::Accept(StructureVisitor^ visitor) {
	visitor->Visit(this);
}