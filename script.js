/* =========================================================
   Meher Prateek — Web Developer Intern Portfolio
   script.js — nav behavior, scroll reveal, typing effect,
   active tab highlighting, and contact form handling.
   ========================================================= */

document.addEventListener('DOMContentLoaded', () => {
  initMobileMenu();
  initSmoothScrollClose();
  initScrollReveal();
  initActiveNavTab();
  initTypingEffect();
  initBackToTop();
  initContactForm();
  initFooterYear();
});

/* ---------------------------------------------------------
   Mobile menu toggle
   --------------------------------------------------------- */
function initMobileMenu() {
  const burger = document.getElementById('navBurger');
  const menu = document.getElementById('mobileMenu');
  if (!burger || !menu) return;

  burger.addEventListener('click', () => {
    const isOpen = menu.classList.toggle('is-open');
    burger.classList.toggle('is-open', isOpen);
    burger.setAttribute('aria-expanded', String(isOpen));
  });
}

/* Close mobile menu whenever a link inside it is used */
function initSmoothScrollClose() {
  const menu = document.getElementById('mobileMenu');
  const burger = document.getElementById('navBurger');
  if (!menu) return;

  menu.querySelectorAll('a').forEach((link) => {
    link.addEventListener('click', () => {
      menu.classList.remove('is-open');
      burger?.classList.remove('is-open');
      burger?.setAttribute('aria-expanded', 'false');
    });
  });
}

/* ---------------------------------------------------------
   Scroll reveal animations (IntersectionObserver)
   --------------------------------------------------------- */
function initScrollReveal() {
  const revealEls = document.querySelectorAll('.reveal');
  if (!revealEls.length) return;

  // If the browser doesn't support IntersectionObserver, just show everything.
  if (!('IntersectionObserver' in window)) {
    revealEls.forEach((el) => el.classList.add('is-visible'));
    return;
  }

  const observer = new IntersectionObserver(
    (entries) => {
      entries.forEach((entry) => {
        if (entry.isIntersecting) {
          entry.target.classList.add('is-visible');
          observer.unobserve(entry.target);
        }
      });
    },
    { threshold: 0.15, rootMargin: '0px 0px -40px 0px' }
  );

  revealEls.forEach((el) => observer.observe(el));
}

/* ---------------------------------------------------------
   Highlight the active nav tab based on scroll position
   --------------------------------------------------------- */
function initActiveNavTab() {
  const sections = document.querySelectorAll('main section[id]');
  const tabs = document.querySelectorAll('.nav__tab');
  if (!sections.length || !tabs.length) return;

  const tabById = new Map();
  tabs.forEach((tab) => {
    const href = tab.getAttribute('href')?.replace('#', '');
    if (href) tabById.set(href, tab);
  });

  if (!('IntersectionObserver' in window)) return;

  const observer = new IntersectionObserver(
    (entries) => {
      entries.forEach((entry) => {
        const tab = tabById.get(entry.target.id);
        if (!tab) return;
        if (entry.isIntersecting) {
          tabs.forEach((t) => t.classList.remove('is-active'));
          tab.classList.add('is-active');
        }
      });
    },
    { rootMargin: '-40% 0px -50% 0px', threshold: 0 }
  );

  sections.forEach((section) => observer.observe(section));
}

/* ---------------------------------------------------------
   Hero editor panel: typing effect for "currentlyLearning"
   --------------------------------------------------------- */
function initTypingEffect() {
  const target = document.getElementById('typedLine');
  if (!target) return;

  const phrases = [
    '"React & Next.js"',
    '"TypeScript"',
    '"System Design basics"',
    '"Web Accessibility"',
  ];

  // Respect users who prefer reduced motion: just show the first phrase.
  const prefersReducedMotion = window.matchMedia('(prefers-reduced-motion: reduce)').matches;
  if (prefersReducedMotion) {
    target.textContent = phrases[0];
    return;
  }

  let phraseIndex = 0;
  let charIndex = 0;
  let isDeleting = false;

  const TYPE_SPEED = 65;
  const DELETE_SPEED = 35;
  const PAUSE_AFTER_TYPE = 1400;
  const PAUSE_AFTER_DELETE = 400;

  function tick() {
    const current = phrases[phraseIndex];

    if (!isDeleting) {
      charIndex++;
      target.textContent = current.slice(0, charIndex);

      if (charIndex === current.length) {
        isDeleting = true;
        setTimeout(tick, PAUSE_AFTER_TYPE);
        return;
      }
      setTimeout(tick, TYPE_SPEED);
    } else {
      charIndex--;
      target.textContent = current.slice(0, charIndex);

      if (charIndex === 0) {
        isDeleting = false;
        phraseIndex = (phraseIndex + 1) % phrases.length;
        setTimeout(tick, PAUSE_AFTER_DELETE);
        return;
      }
      setTimeout(tick, DELETE_SPEED);
    }
  }

  tick();
}

/* ---------------------------------------------------------
   Back-to-top button visibility + click
   --------------------------------------------------------- */
function initBackToTop() {
  const btn = document.getElementById('backToTop');
  if (!btn) return;

  const toggleVisibility = () => {
    btn.style.opacity = window.scrollY > 500 ? '1' : '0';
    btn.style.pointerEvents = window.scrollY > 500 ? 'auto' : 'none';
  };

  btn.style.transition = 'opacity 0.25s ease, transform 0.25s ease';
  toggleVisibility();
  window.addEventListener('scroll', toggleVisibility, { passive: true });

  btn.addEventListener('click', () => {
    window.scrollTo({ top: 0, behavior: 'smooth' });
  });
}

/* ---------------------------------------------------------
   Contact form (front-end only demo)
   This is a static site with no backend attached — the form
   validates input and shows a confirmation message. Wire it
   up to a real endpoint (Formspree, EmailJS, your own API,
   etc.) before relying on it to receive real messages.
   --------------------------------------------------------- */
function initContactForm() {
  const form = document.getElementById('contactForm');
  const note = document.getElementById('formNote');
  if (!form || !note) return;

  form.addEventListener('submit', (event) => {
    event.preventDefault();

    if (!form.checkValidity()) {
      note.style.color = 'var(--accent-red)';
      note.textContent = 'Please fill in every field before sending.';
      return;
    }

    const name = form.name.value.trim();

    note.style.color = 'var(--accent-green)';
    note.textContent = `Thanks, ${name}! This demo form doesn't send email yet — connect it to a service like Formspree or EmailJS, or email me directly.`;
    form.reset();
  });
}

/* ---------------------------------------------------------
   Footer year
   --------------------------------------------------------- */
function initFooterYear() {
  const yearEl = document.getElementById('year');
  if (yearEl) {
    yearEl.textContent = new Date().getFullYear();
  }
}
