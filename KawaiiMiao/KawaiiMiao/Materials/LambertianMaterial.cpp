#include "LambertianMaterial.h"

#include "../Core/BSDF.h"
#include "../Tool/Memory.h"
#include "../Core/Spectrum.h"
#include "../Core/Interaction.h"

RENDER_BEGIN

RENDER_REGISTER_CLASS(LambertianMaterial, "Lambertian");

LambertianMaterial::LambertianMaterial(const APropertyTreeNode& node)
{
	const auto& props = node.getPropertyList();
	Vector3f _kr = props.getVector3f("R");
	Float _tmp[] = { _kr.x, _kr.y, _kr.z };
	m_Kr = Spectrum::fromRGB(_tmp);
	activate();
}

void LambertianMaterial::computeScatteringFunctions(SurfaceInteraction& si, MemoryArena& arena,
	TransportMode mode, bool allowMultipleLobes) const
{
	si.bsdf = ARENA_ALLOC(arena, BSDF)(si);
	Spectrum R = m_Kr;
	if (!R.isBlack())
	{
		si.bsdf->add(ARENA_ALLOC(arena, LambertianReflection)(R));
	}
}

RENDER_END