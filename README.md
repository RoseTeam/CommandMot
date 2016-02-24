# CommandMot

Pour l'édition du code de la carte moteur via Visual Studio :

- installer microsoft ![Visual Studio Community](https://www.visualstudio.com/en-us/downloads/download-visual-studio-vs.aspx), choisir le c++ dans les modules optionnels à l'installation (ce n'est pas inclus par défaut)
- installer le module python platformio. Il marche avec python2, pas python3 pour l'instant. Installer pip si ce n'est déjà fait dans votre installation de python 2.7. et faire :

```
pip install platformio
```
- s'assurer que platformio est dans le chemin windows (taper platformio dans une fenêtre cmd, ça doit marcher). Relancer Visual Studio après une mise à jour du PATH pour que les changements soient pris en compte
- ouvrir la solution qui se trouve dans nucleoF401re/nucleoF401re
- S'assurer que la solution est bien compilée en x86 (pas x64):


voilà !
