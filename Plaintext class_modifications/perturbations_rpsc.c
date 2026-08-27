C
/**
 * perturbations_rpsc.c
 * 
 * Linear Scalar Perturbation Evolution for Relational Phase-Space Cosmology (RPSC)
 * Implements gauge-invariant perturbation dynamics for saturated k-essence:
 *   P(X) = X / (1 + \alpha * X / X0) - V0
 * Reference: RPSC Paper VI (2026)
 */

#include "perturbations.h"

/**
 * Computes source terms and evolution derivatives for the RPSC scalar field
 * perturbations in Synchronous and Conformal Newtonian gauges.
 */
int perturbations_rpsc_derivs(
    struct precision *ppr,
    struct background *pba,
    struct perturbations *ppt,
    double tau,
    double *y,
    double *dy,
    double k,
    double a,
    double a_prime_over_a,  /* Conformal Hubble parameter: \mathcal{H} */
    double phi,
    double phi_prime,
    double X0,
    double alpha,
    double V0,
    int gauge_choice        /* 0: Synchronous gauge, 1: Newtonian gauge */
) {
    /* 1. Kinetic term and dimensionless saturation variable */
    double X = (phi_prime * phi_prime) / (2.0 * a * a);
    double u = (alpha * X) / X0;

    /* Cap at ghost-free physical boundary */
    if (u >= 0.3333333333333333) {
        u = 0.333333;
    }

    double denom = 1.0 + u;
    double denom2 = denom * denom;

    /* 2. Background thermodynamic quantities */
    double rho_phi = (X * (2.0 + u)) / denom2 + V0;
    double p_phi   = (X / denom) - V0;
    double w_phi   = (rho_phi > 0.0) ? (p_phi / rho_phi) : -1.0;

    /* 3. Dynamical Rest-Frame Sound Speed: c_s^2 = (1 - 3u) / (1 + u) */
    double cs2 = (1.0 - 3.0 * u) / (1.0 + u);
    if (cs2 > 1.0) cs2 = 1.0;
    if (cs2 < 0.0) cs2 = 0.0;

    /* 4. Adiabatic sound speed: c_a^2 = P' / \rho' */
    /* For pure kinetic k-essence without potential slope: c_a^2 = w_phi */
    double ca2 = w_phi;

    /* 5. Field perturbation state variables:
     *    y[0] = \delta\phi (field perturbation)
     *    y[1] = \delta\phi' (derivative of field perturbation)
     *    y[2] = h, y[3] = h_prime (metric perturbations in synchronous gauge)
     */
    double delta_phi       = y[0];
    double delta_phi_prime = y[1];

    /* 6. First derivative of field perturbation */
    dy[0] = delta_phi_prime;

    /* 7. Second-order perturbation equation of motion:
     *    \delta\phi'' + 2\mathcal{H} [1 + (c_s^2 - c_a^2)/(1+w)] \delta\phi' 
     *    + [c_s^2 k^2 + a^2 V_{,\phi\phi}] \delta\phi = Metric Source Terms
     */
    double friction_coeff = 2.0 * a_prime_over_a * (1.0 + (cs2 - ca2) / (1.0 + w_phi + 1e-15));
    double k2_term = cs2 * k * k * delta_phi;

    if (gauge_choice == 0) {
        /* Synchronous Gauge: Source term = (1/2) * \phi' * h' */
        double h_prime = y[3];
        dy[1] = - friction_coeff * delta_phi_prime - k2_term + 0.5 * phi_prime * h_prime;
    } else {
        /* Conformal Newtonian Gauge: Source term = \phi' * (\psi' + 3\phi_metric') - 2 a^2 V_{,\phi} \psi */
        double psi_prime = y[2];
        double phi_metric_prime = y[3];
        dy[1] = - friction_coeff * delta_phi_prime - k2_term + phi_prime * (psi_prime + 3.0 * phi_metric_prime);
    }

    return _SUCCESS_;
}
