C
/**
 * background_rpsc.c
 * 
 * Saturated Kinetic K-Essence Thermodynamics for Relational Phase-Space Cosmology (RPSC)
 * Implements: P(X) = X / (1 + \alpha * X / X0) - V0
 * Reference: RPSC Paper VI (2026)
 */

#include "background.h"

int background_rpsc_thermodynamics(
    double phi,
    double phi_prime,
    double a,
    double a_prime,
    double X0,
    double alpha,
    double V0,
    double *rho_phi,
    double *p_phi,
    double *w_phi,
    double *cs2_phi
) {
    /* 1. Kinetic density in conformal time: X = (phi')^2 / (2 * a^2) */
    double X = (phi_prime * phi_prime) / (2.0 * a * a);
    
    /* 2. Dimensionless saturation variable: u = alpha * X / X0 */
    double u = (alpha * X) / X0;
    
    /* 3. Physical phase-space stability boundary condition (Ghost-free check) */
    if (u >= 0.3333333333333333) {
        /* Cap at stability margin to prevent non-hyperbolic gradient divergence */
        u = 0.333333;
    }
    
    double denom = 1.0 + u;
    double denom2 = denom * denom;
    
    /* 4. Background Energy Density: \rho = X(2 + u)/(1 + u)^2 + V0 */
    *rho_phi = (X * (2.0 + u)) / denom2 + V0;
    
    /* 5. Background Pressure: P = X / (1 + u) - V0 */
    *p_phi = (X / denom) - V0;
    
    /* 6. Equation of State: w = P / \rho */
    if (*rho_phi > 0.0) {
        *w_phi = (*p_phi) / (*rho_phi);
    } else {
        *w_phi = -1.0;
    }
    
    /* 7. Rest-frame Sound Speed: c_s^2 = (1 - 3u) / (1 + u) */
    *cs2_phi = (1.0 - 3.0 * u) / (1.0 + u);
    
    /* Strict causality bounds: c_s^2 in (0, 1] */
    if (*cs2_phi > 1.0) *cs2_phi = 1.0;
    if (*cs2_phi < 0.0) *cs2_phi = 0.0;
    
    return _SUCCESS_;
}
