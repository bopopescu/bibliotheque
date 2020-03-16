jQuery( document ).ready( function ( $ ) {
	var tooltips = [];

	$( '.glossary-item-container' ).each( function( index, element ) {

		var tooltipContent = $( element ).find( '.glossary-item-hidden-content' ).detach().html();

		var tooltip = tippy(element, {
			content: tooltipContent,
			allowHTML: true,
			arrow: true,
			theme: 'light',
			delay: [0, 2000],
			onShow: function(instance) {

				for (var i = 0; i < tooltips.length; i++) {
					if ( instance.id !== tooltips[i].id ) {
						tooltips[i].hide();
					}
				}
			},
			interactive: true,
			boundary: 'window',
		});

		tooltips.push(tooltip);
	} );
} );
