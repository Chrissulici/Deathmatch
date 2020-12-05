## SEARCH: ( __MAKEDIALOGS )

	def OpenRestartDialog(self):
		self.dlgRestart.OpenDialog()
		self.dlgRestart.SetTop()

		
## REPLACE:

	def OpenRestartDialog(self):
		if app.ENABLE_DEATHMATCH_SYSTEM:
			if player.IsDeathMatchMap():
				self.dlgRestart.Hide()
			else:
				self.dlgRestart.OpenDialog()
				self.dlgRestart.SetTop()
		else:
			self.dlgRestart.OpenDialog()
			self.dlgRestart.SetTop()

