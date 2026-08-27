
# Relational Phase-Space Cosmology (RPSC)

Official repository for the six-part paper series on **Relational Phase-Space Cosmology (RPSC)**:
*Non-singular quantum bouncing cosmology, galactic kinematics, JWST early structure formation, and joint resolution of the H0 and S8 tensions.*

---

## 📄 Papers in the Series

1. **Paper I:** Foundations of Relational Phase-Space Mechanics
2. **Paper II:** Regular Black Hole Interiors & Elimination of Singularities
3. **Paper III:** Non-Singular Cosmic Bounce Dynamics
4. **Paper IV:** Galactic Rotation Curves & Dwarf Core-Cusp Resolution
5. **Paper V:** Accelerated High-z Structure Formation (JWST Concordance)
6. **Paper VI:** Linear Perturbation Theory, Boltzmann System Architecture, and Joint MCMC Concordance

---

Markdown
## ⚙️ Core Model Architecture

Spacetime geometry emerges from a capacity-bounded relational scalar field governed by the saturated kinetic Lagrangian:

$$
P(X) = \frac{X}{1 + \frac{\alpha X}{X_0}} - V_0 \quad \text{with } \alpha = \frac{1}{4}
$$

* **Dynamical Stability:** Ghost-free ($\rho_{,X} > 0$), strictly hyperbolic, and causal ($0 < c_s^2 \le 1$).
* **Effective Energy Density:**

$$
\rho_\Phi = \frac{X(2 + u)}{(1 + u)^2} + V_0 \quad \text{where } u \equiv \frac{\alpha X}{X_0}
$$

* **Rest-Frame Sound Speed:**

$$
c_s^2 = \frac{1 - 3u}{1 + u} \in (0, 1]
$$

* **Cosmological Best-Fit:** 
  * $H_0 = 73.18 \pm 0.82 \text{ km s}^{-1}\text{Mpc}^{-1}$
  * $S_8 = 0.774 \pm 0.012$
  * $\Delta\chi^2 = -17.42$ relative to flat $\Lambda\text{CDM}$.

---

## 💻 Repository Contents

* `/class_modifications/` — Modified `background.c` and `perturbations.c` source routines for the CLASS Boltzmann solver.
* `/mcmc_chains/` — Cobaya configuration files and converged posterior parameter chains.
* `/notebooks/` — Python scripts for CMB power spectra and matter power spectra $P(k)$.

---


## 📜 Citation

If you use this model, Boltzmann modifications, or numerical chains in your research, please cite:

> Dan Sykes, *Relational Phase-Space Cosmology (RPSC): VI. Linear Perturbation Theory, Boltzmann System Architecture, and Joint MCMC Concordance* (2026).
