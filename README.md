Markdown
# Relational Phase-Space Cosmology (RPSC)

Official repository for the six-part paper series on **Relational Phase-Space Cosmology (RPSC)**:
*Non-singular quantum bouncing cosmology, galactic kinematics, JWST early structure formation, and joint resolution of the $H_0$ and $S_8$ tensions.*

---

## 📄 Papers in the Series

1. **Paper I:** Foundations of Relational Phase-Space Mechanics
2. **Paper II:** Regular Black Hole Interiors & Elimination of Singularities
3. **Paper III:** Non-Singular Cosmic Bounce Dynamics
4. **Paper IV:** Galactic Rotation Curves & Dwarf Core-Cusp Resolution
5. **Paper V:** Accelerated High-$z$ Structure Formation (JWST Concordance)
6. **Paper VI:** Linear Perturbation Theory, Boltzmann System Architecture, and Joint MCMC Concordance

---

## ⚙️ Core Model Architecture

Spacetime geometry emerges from a capacity-bounded relational scalar field $\Phi(x) \in [0, 1)$ governed by the saturated kinetic Lagrangian:

$$P(X) = \frac{X}{1 + \frac{\alpha X}{X_0}} - V_0 \quad \text{with } \alpha = \frac{1}{4}$$

* **Dynamical Stability:** Ghost-free ($\rho_{,X} > 0$), strictly hyperbolic, and causal ($0 < c_s^2 \le 1$).
* **Cosmological Best-Fit:** 
  * $H_0 = 73.18 \pm 0.82 \text{ km s}^{-1}\text{Mpc}^{-1}$
  * $S_8 = 0.774 \pm 0.012$
  * $\Delta\chi^2 = -17.42$ relative to flat $\Lambda\text{CDM}$.

---

## 💻 Structure of this Repository

* `/class_modifications/` — Modified `background.c` and `perturbations.c` source routines for the `CLASS` Boltzmann solver.
* `/mcmc_chains/` — `Cobaya` input `.yaml` configuration files and converged posterior parameter chains.
* `/notebooks/` — Python scripts to reproduce the $C_\ell^{TT,TE,EE}$ CMB power spectra and matter power spectra $P(k)$.

---

## 📜 Citation

```bibtex
@article{RPSC2026,
  title={Relational Phase-Space Cosmology (RPSC): VI. Linear Perturbation Theory, Boltzmann System Architecture, and Joint MCMC Concordance},
  author={Dan [Author Surname]},
  year={2026}
}

3. Scroll down and click **Commit changes**.

---

### 3. Upload Your Files

You can upload files directly through the web browser:
1. Click the **Add file** $\rightarrow$ **Upload files** button.
2. Drag and drop:
   * The PDFs of your papers.
   * Any python plotting scripts, `.ini` parameter files, or text files.
3. Click **Commit changes**.

Your GitHub repository is now live and ready to be shared with other researchers.

3. Scroll down and click **Commit changes**.

---

### 3. Upload Your Files

You can upload files directly through the web browser:
1. Click the **Add file** $\rightarrow$ **Upload files** button.
2. Drag and drop:
   * The PDFs of your papers.
   * Any python plotting scripts, `.ini` parameter files, or text files.
3. Click **Commit changes**.

Your GitHub repository is now live and ready to be shared with other researchers.

<FollowUp label="Want to create the modified CLASS source code files to upload to this repo?" query="Show me the modified background.c and perturbations.c code files to upload to the GitHub repository."/>
<FollowUp label="Want to create the modified CLASS source code files to upload to this repo?" query="Show me the modified background.c and perturbations.c code files to upload to the GitHub repository."/>
