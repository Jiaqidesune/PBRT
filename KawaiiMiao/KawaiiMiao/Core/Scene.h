#pragma once

#include "Rendering.h"
#include "Light.h"
#include "Primitive.h"
#include "Rtti.h"
#include "../Math/KMathUtil.h"

RENDER_BEGIN

class Scene
{
public:
	typedef std::shared_ptr<Scene> ptr;

	Scene(const HitableAggregate::ptr& hitables, const std::vector<Light::ptr>& lights)
		: m_lights(lights), m_aggreShape(hitables)
	{
		for (const auto& light : lights)
		{
			light->preprocess(*this);
			if (light->flags & (int)LightFlags::LightInfinite)
				m_infiniteLights.push_back(light);
		}
	}

	const Bounds3f& worldBound() const { return m_worldBound; }

	bool hit(const Ray& ray) const;
	bool hit(const Ray& ray, SurfaceInteraction& isect) const;
	bool hitTr(Ray ray, Sampler& sampler, SurfaceInteraction& isect, Spectrum& transmittance) const;

	std::vector<Light::ptr> m_lights;
	// Store infinite light sources separately for cases where we only want
	// to loop over them.
	std::vector<Light::ptr> m_infiniteLights;

private:
	// Scene Private Data
	Bounds3f m_worldBound;
	HitableAggregate::ptr m_aggreShape;
};

RENDER_END