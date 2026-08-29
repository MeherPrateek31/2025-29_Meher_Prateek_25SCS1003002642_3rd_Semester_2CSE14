# Meher Prateek — Web Developer Intern Portfolio

A modern, responsive portfolio website built for a Web Developer Internship, showcasing
projects, skills, and internship learnings. Built with plain **HTML, CSS, and JavaScript**
— no frameworks, no build step, ready to deploy straight to GitHub Pages.

**Design concept:** the whole site is styled like a code editor / GitHub dark theme —
navigation tabs look like open editor files (`home.tsx`, `about.md`, `skills.json`...),
projects are shown as repo-style cards, and the "What I Learned" section reads like a
git commit log. It's a portfolio that looks and feels like the world of the person who built it.

---

## 📁 Project Structure

```
2025-29_Meher_Prateek_25SCS1003002642_3rd_Semester_2CSE14/
│
├── index.html      # Page structure & content
├── style.css       # All styling (design system, layout, responsiveness, animations)
├── script.js       # Interactivity (nav, scroll reveal, typing effect, form)
└── README.md       # This file
```

---

## ✨ Features

- **Hero / Home** — introduction with a live "typing" code editor mockup
- **About Me** — profile card + bio + quick facts
- **Skills** — categorized, chip-based skill groups (Languages, Frontend, Backend, Tools)
- **Internship Projects** — repo-style project cards with tags, highlights, and links
- **What I Learned** — a git-log-styled timeline of internship takeaways
- **Contact** — validated contact form (front-end only) + direct contact links
- **Professional Footer** — sitemap links, social icons, back-to-top button
- Fully **responsive** (desktop, tablet, mobile) with a mobile hamburger menu
- **Smooth scrolling**, scroll-triggered reveal animations, and active-tab highlighting
- Respects `prefers-reduced-motion` for accessibility
- No external JS dependencies — vanilla JavaScript only

---

## 🛠️ Customization Guide

Before deploying, replace the placeholder content with your own:

### 1. Personal details (`index.html`)
- Replace **"Meher Prateek"** with your name throughout the file.
- Update the `<title>` and `<meta name="description">` tags in `<head>`.
- Update the **About** section: location, education, availability, bio text.
- Update the initials in `.about__avatar` (currently `AS`).

### 2. Links
Search for these placeholders and replace them with your real links:
- `https://github.com/MeherPrateek31` → GitHub profile (the LinkedIn icon links here too — swap it for your LinkedIn URL if you'd rather use that)
- `mailto:meher.prateek@example.com` → your email
- `tel:+910000000000` → your phone number
- Each project's `href="https://github.com/MeherPrateek31/..."` and `Live Demo` links

### 3. Skills
Edit the `.chip` items inside the `#skills` section to match your actual stack.

### 4. Projects
Each `<article class="project-card">` in the `#projects` section can be duplicated,
edited, or removed. Update the title, description, tags, highlights, and links for
your real internship/academic projects.

### 5. What I Learned
Edit the `<li class="commit">` items inside `#learnings` — each one represents a
takeaway from your internship, styled like a commit message.

### 6. Contact form
The contact form is **front-end only** — it validates input and shows a confirmation
message, but does not send real emails. To make it functional, connect it to a service
such as:
- [Formspree](https://formspree.io/)
- [EmailJS](https://www.emailjs.com/)
- Your own backend/API endpoint

Update the `<form>` element's `action`/`fetch` logic in `script.js` accordingly.

### 7. Colors & fonts
All design tokens live at the top of `style.css` inside `:root { ... }` — change the
CSS variables there to re-theme the entire site.

---

## 💻 How to Run Locally

1. Download or clone this repository.
2. Open the `2025-29_Meher_Prateek_25SCS1003002642_3rd_Semester_2CSE14` folder in VS Code (or any code editor).
3. Open `index.html` with the **Live Server** extension (or any local server).

The project can also be opened directly in a browser by double-clicking `index.html`
— no server is required, since the site uses only static HTML, CSS, and JavaScript.

---

## 🚀 Live Demo

[Live Demo](https://meherprateek31.github.io/2025-29_Meher_Prateek_25SCS1003002642_3rd_Semester_2CSE14/)

*(Live once GitHub Pages is enabled for this repository — see [Deploying to GitHub Pages](#-deploying-to-github-pages) below.)*

---

## 🖼️ Screenshots

Screenshots are not yet included in this repository. Once available, they can be
added here, for example:

```
![Homepage](assets/homepage.png)
```

---

## 🎓 Internship Project

This project was developed as a Web Development internship/portfolio project to
demonstrate practical, framework-free frontend development skills — including
responsive layout, DOM interactivity, and clean, well-organized code.

---

## 🌐 Deploying to GitHub Pages

Your repository already exists at:
https://github.com/MeherPrateek31/2025-29_Meher_Prateek_25SCS1003002642_3rd_Semester_2CSE14

1. **Clone it** (or `cd` into it if you already have it locally):

   ```bash
   git clone https://github.com/MeherPrateek31/2025-29_Meher_Prateek_25SCS1003002642_3rd_Semester_2CSE14.git
   cd 2025-29_Meher_Prateek_25SCS1003002642_3rd_Semester_2CSE14
   ```

2. **Copy `index.html`, `style.css`, `script.js`, and `README.md`** into the root of
   that folder (replacing the existing `README.md` if there is one), then push:

   ```bash
   git add .
   git commit -m "Add internship portfolio site"
   git push
   ```

3. On GitHub, go to the repository → **Settings** → **Pages**.
4. Under **"Build and deployment"**, set:
   - **Source:** `Deploy from a branch`
   - **Branch:** `main` (or `master`) / folder: `/ (root)`
5. Click **Save**. After a minute or two, your site will be live at:

   ```
   https://meherprateek31.github.io/2025-29_Meher_Prateek_25SCS1003002642_3rd_Semester_2CSE14/
   ```

---

## ♿ Accessibility Notes

- All interactive elements have visible focus states.
- Icons include `aria-label`s where they aren't paired with visible text.
- Animations are disabled automatically for users with `prefers-reduced-motion` enabled.
- Form fields use proper `<label>` elements and `required` validation.

---

## 📄 License

Free to use and adapt for your own portfolio. No attribution required.
